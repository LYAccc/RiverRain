

#include <string>
#include <fcntl.h>      
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "config.h"

using block_id_t = int;
namespace riverrain{
class DiskManager{
    public:
        explicit DiskManager(const char * path_name);

        void ShutDown();


        virtual void WriteBlockToDisk(block_id_t block_id, const char *block_data);

        virtual void ReadBlockFromDisk(block_id_t block_id, char * block_data);

    protected:
        int fd_;
        const char * path_name_;
        

};
}
