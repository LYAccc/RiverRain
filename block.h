
#include "config.h"

namespace riverrain{
    class Block{

    friend class BufferPoolManager; 
    Block(){};

    ~Block(){
        delete[] data_;
    }
    
    private:
         char  data_[BLOCK_SIZE];
         int pin_count_ = 0;
         bool is_dirty_ = false;

    };
}