

#include <string>
#include <fcntl.h>      


using block_id_t = int;

class DiskManager{
    public:
        explicit DiskManager(const char * path_name);

        void ShutDown();


        virtual void WritePage(block_id_t block_id, const char *block_data);

        virtual void ReadPage(block_id_t block_id, char * block_data);

    protected:
        int fd_;
        const char * path_name_;
        

};