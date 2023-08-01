#ifndef BLOCK_BF
#define BLOCK_BF
#include "config.h"

namespace riverrain{
    class Block{

    friend class  MemoryManager; 
    Block(){};
    ~Block(){};
    public:
    int a = 5; // for test purpose 
    // ~Block(){
    //     delete[] data_;
    // }
    
    private:
         char  data_[BLOCK_SIZE];
         int pin_count_ = 0;
         bool is_dirty_ = false;
         block_id_t block_id_ = INVALID_PAGE_ID;                                           // invalid page id
    };
}
#endif
