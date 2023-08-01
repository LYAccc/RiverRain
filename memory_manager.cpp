#include "memory_manager.h" 


// to do initilize a block 

namespace riverrain{
      MemoryManager:: MemoryManager(size_t pool_size_bytes, DiskManager * disk_manager): mem_pool_size_(pool_size_bytes/BLOCK_SIZE) {
                            blocks_ = allocate(mem_pool_size_);
                            for (size_t i = 0; i < mem_pool_size_; ++i) {
                                    free_list_.emplace_back(static_cast<int>(i));
                            }
    }
     MemoryManager::~ MemoryManager(){
             for(int i = 0; i < mem_pool_size_;++i){
                blocks_[i].~Block();
             }
             
             free(blocks_);           
    }

    auto  MemoryManager::allocate(size_t pz) -> Block *{
         void * raw_ptr = aligned_alloc(1024, sizeof(Block) * pz);
                                 auto obj_ptr = new(raw_ptr) Block[pz];
                                 return obj_ptr;

    }

    auto  MemoryManager::FlushBlock(block_id_t b_id) -> bool{

                                auto ite = block_table_.find(b_id);
                                if(ite == block_table_.end()){
                                        return false;
                                }
                                auto f_id = (*ite).second;
                                this->disk_manager_->WriteBlockToDisk(b_id, reinterpret_cast<char *> (&blocks_[f_id]));
                                return true;

    }

    auto  MemoryManager::FetchBlock(block_id_t b_id) -> Block *{
                      
                        const std::lock_guard<std::mutex> lock(latch_);
                        latch_.lock();
                        auto ite = this->block_table_.find(b_id);
                        if(ite != block_table_.end()){
                                auto f_id = (*ite).second;
                                
                                return &blocks_[f_id];
                        }
                        frame_id_t avaliable_frame;
                        if(!this->free_list_.empty()){
                                auto ite_fl = free_list_.end();
                                avaliable_frame = *ite_fl;
                                free_list_.erase(ite_fl);
                                block_table_[b_id] = avaliable_frame;
                                this->disk_manager_->ReadBlockFromDisk(b_id, reinterpret_cast<char *> (&blocks_[avaliable_frame]));
                                
                                
                                return &blocks_[avaliable_frame];
                        }

                        (*replacer_).Evict(&avaliable_frame);
                        Block * old_block = &blocks_[avaliable_frame];
                        if(old_block->is_dirty_){
                                FlushBlock(old_block->block_id_);
                        }
                        block_table_[b_id] = avaliable_frame;
                        
                        this->disk_manager_->ReadBlockFromDisk(b_id, reinterpret_cast<char *> (&blocks_[avaliable_frame]));
                        
                        return &blocks_[avaliable_frame];


                        
    }



    
}

