#include "object_block.h"

namespace riverrain{
    auto ObjectBlock::GetRemainingSize() const -> size_t{
            return 1;
    }

    auto ObjectBlock::ContentAt(int index) const -> std::pair<const char *, size_t>{
                // out of index
                if(index >= this->object_nums_ || index < 0 ){
                    throw std::runtime_error(" index out of range ");
                    // return std::make_pair<char *, size_t>(nullptr,0);
                }
                size_t offset = this->offset_map_[index];
                const char * end_of_block = reinterpret_cast<const char *>(this) + (OBJECT_BLOCK_SIZE);
                size_t len = 0;
                if(index == 0){
                      len = offset_map_[index];
                }
                else{
                      len = offset_map_[index] - offset_map_[index-1];
                }
                return std::make_pair(end_of_block - offset, len);


    }
    
}