#include "disk_manager.hpp"


DiskManager::DiskManager(const char * pname) : path_name_{pname} {
            fd_ = open(path_name_, O_RDWR | O_DIRECT)
}