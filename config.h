
namespace riverrain{
    
    constexpr size_t BLOCK_SIZE = 4096 * 4;
    constexpr size_t DISK_SIZE = BLOCK_SIZE * 100;
    constexpr size_t BUFFER_POOL_SIZE = BLOCK_SIZE * 5;

    using block_id_t = int;
    using frame_id_t = int;

}