#include "disk_manager.h"
#include "block.h"
#include <unordered_map>
#include <list>

namespace riverrain{
    class BufferPoolManager{
               BufferPoolManager(size_t pool_size_bytes, DiskManager * disk_manager);
               private:
                Block *blocks_;
                std::unordered_map<block_id_t, frame_id_t> block_table_;
                std::list<frame_id_t> free_list_;
                const size_t pool_size_;
                DiskManager *disk_manager_;

    };
}

