


#ifndef HEADER_CONFIG
#define HEADER_CONFIG

namespace riverrain{
    static constexpr int INVALID_BLOCK_ID = -1;                                           // invalid block id
    static constexpr int BLOCK_SIZE = 4096 * 4;
    static constexpr int DISK_SIZE = BLOCK_SIZE * 100;
    static constexpr int BUFFER_POOL_SIZE = BLOCK_SIZE * 5;
    
    static constexpr int BLOCK_META_SIZE  = 12;

    using block_id_t = int;
    using frame_id_t = int;
    using slot_id_t = int;
    
    struct index{
        block_id_t b_id;
        frame_id_t f_id;
    };
    
}


#endif
