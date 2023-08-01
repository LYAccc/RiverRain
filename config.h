


#ifndef HEADER_CONFIG
#define HEADER_CONFIG
namespace riverrain{
    static constexpr int INVALID_BLOCK_ID = -1;                                           // invalid block id
    constexpr size_t BLOCK_SIZE = 4096 * 4;
    constexpr size_t DISK_SIZE = BLOCK_SIZE * 100;
    constexpr size_t BUFFER_POOL_SIZE = BLOCK_SIZE * 5;


    using block_id_t = int;
    using frame_id_t = int;
    using slot_id_t = int;
    
    struct index{
        block_id_t b_id;
        frame_id_t f_id;
    };
    
}


#endif
