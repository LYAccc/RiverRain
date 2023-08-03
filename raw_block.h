#ifndef BLOCK_BF
#define BLOCK_BF
#include "config.h"

namespace riverrain{
  
    class RawBlock{

    friend class  MemoryManager; 
    public:
    RawBlock(){};
    ~RawBlock(){};
   
    private:
         int pin_count_ = 0;
         block_id_t block_id_ = INVALID_BLOCK_ID;                                           // invalid page id
         bool is_dirty_ = false;
         char  data_[BLOCK_SIZE - BLOCK_META_SIZE];
    };
}
#endif
