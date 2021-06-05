#include "zdef.hpp"
#include <string.h>

namespace zstd {
    uint64 hash(const char* str) {
        uint64 hash = 0;
        uint64 len = strlen(str);
        for (uint64 i = 0; i < len; i++) {
            int code = int(str[i]);
            hash += (i+1) * code;
        }
        hash *= len;
        return hash;
    }
}
