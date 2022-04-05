//
// Created by Ming Yu on 2022/3/15.
//

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <libpmem.h>
#include <unistd.h>


#define NVMPATH "/data/yuming/nvmDir/test.txt"
#define PMEM_LEN 34359738368 // 34359738368 B = 32 GB

const int PAGE_QUEUE_SLOT_MULTI_NBUFFERS = 5;

void *getNvmBlockPoint(Size size, bool *foundPtr, bool *found_descs) {
    void *pmemaddr = NULL;
    if (*found_descs == false) {
        *foundPtr = false;
        return pmemaddr;
    }
    size_t mapped_len = size;

    int is_pmem;
    /* create a pmem file and memory map it */
    if ((pmemaddr = pmem_map_file(NVMPATH, PMEM_LEN, PMEM_FILE_CREATE,
                                  0666, &mapped_len, &is_pmem)) == NULL) {
        *foundPtr = false;
    } else {
        *foundPtr = true;
    }
    /* init database process and run database process are unique. */

    return pmemaddr;
}

/*
// using 4k of pmem for this example
#define PMEM_LEN 4096

#define PATH "/pmem-fs/myfile"

int
main(int argc, char *argv[])
{
    char *pmemaddr;
    size_t mapped_len;
    int is_pmem;

    // create a pmem file and memory map it
    if ((pmemaddr = pmem_map_file(PATH, PMEM_LEN, PMEM_FILE_CREATE,
                                  0666, &mapped_len, &is_pmem)) == NULL) {
        perror("pmem_map_file");
        exit(1);
    }

    // store a string to the persistent memory
    strcpy(pmemaddr, "hello, persistent memory");

    // flush above strcpy to persistence
    if (is_pmem)
        pmem_persist(pmemaddr, mapped_len);
    else
        pmem_msync(pmemaddr, mapped_len);


//     * Delete the mappings. The region is also
//     * automatically unmapped when the process is
//     * terminated.

    pmem_unmap(pmemaddr, mapped_len);
    return 0;
}

*/