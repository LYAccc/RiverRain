#include "buffer_pool_manager.h" 

namespace riverrain{
     BufferPoolManager::BufferPoolManager(size_t pool_size_bytes, DiskManager * disk_manager): pool_size_(pool_size_bytes/BLOCK_SIZE) {
                            blocks_ = new Block[pool_size_];
                            for (size_t i = 0; i < pool_size_; ++i) {
                                    free_list_.emplace_back(static_cast<int>(i));
                            }
    }
}

