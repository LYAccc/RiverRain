#ifndef OBJECT_BLOCK_BF
#define OBJECT_BLOCK_BF
#include "config.h"
#include <utility>


/**
 * Store n indexed keys and n+1 child pointers (page_id) within internal page.
 * Pointer PAGE_ID(i) points to a subtree in which all keys K satisfy:
 * K(i) <= K < K(i+1).
 * NOTE: since the number of keys does not equal to number of child pointers,
 * the first key always remains invalid. That is to say, any search/lookup
 * should ignore the first key.
 *
 *  format (keys are stored in increasing order):
 *  --------------------------------------------------------------------------
 * | HEADER | OBJECT END OFFSET(1) | OBJECT END OFFSET(2) | ... | OBJECT END OFFSET(N) |
 * 
 *                                           |OBJECT CONTETNT(N) | .......                 
 *                                      .....| OBJECT CONTENT(2)| OBJECT CONTENT(1)    | 
 *  --------------------------------------------------------------------------
 */

namespace riverrain{

#define OBJECT_BLOCK_HEADER_SIZE 8
#define OBJECT_BLOCK_SIZE = BLOCK_SIZE - BLOCK_META_SIZE - 8

    class ObjectBlock{

    friend class  MemoryManager;
    public: 
    ObjectBlock(){};
    ~ObjectBlock(){};
    auto ContentAt(int index) const -> std::pair<char *, int>;
    auto GetRemainingSize() const -> int;
    
    private:
         int ptr_end_;
         int object_nums_;
         int offset_map_[0];
         char * ptr_data_start_ = &(reinterpret_cast<char *>(this)[OBJECT_BLOCK_SIZE]);
         
    };
}
#endif