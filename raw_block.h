#ifndef BLOCK_BF
#define BLOCK_BF
#include "config.h"

namespace riverrain{
#define RAW_BLOCK_HEADER_SIZE 12
    class RawBlock{
    
    friend class  MemoryManager; 
    public:
    RawBlock(){};
    ~RawBlock(){};
    auto GetData() -> char *{
        return data_;
    }
   
    private:
         int pin_count_ = 0;
         block_id_t block_id_ = INVALID_BLOCK_ID;                                           // invalid page id
         bool is_dirty_ = false;
         char  data_[RAW_BLOCK_SIZE - RAW_BLOCK_HEADER_SIZE];
    };
}
#endif
