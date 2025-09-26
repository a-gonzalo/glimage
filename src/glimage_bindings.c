#include "glimage_bindings.h"

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#ifdef GC
#define STBI_MALLOC(p)          GC_MALLOC(p)
#define STBI_FREE(p)            GC_FREE(p)
#define STBI_REALLOC(p,newsz)   GC_REALLOC(p,newsz)

#define STBIW_MALLOC(sz)        GC_MALLOC(sz)
#define STBIW_REALLOC(p,newsz)  GC_REALLOC(p,newsz)
#define STBIW_FREE(p)           GC_FREE(p)
#endif
#include "stb_image.h"
#include "stb_image_write.h"



glimage_bindings_Image glimage_stbi_load(String filename) {
    glimage_bindings_Image rtn;
    int x, y, n;
    const char * fn = filename.bytes;
    unsigned char *data = stbi_load(fn, &x, &y, &n, 0);
    if (data == NULL) printf("Error opening file: %s\n", stbi_failure_reason());
    rtn.channels =  (int64_t) n;
    rtn.data.bytes = (char*) data;
    rtn.data.byte_length =  x * y * n;
    rtn.h = (int64_t) y;
    rtn.w = (int64_t) x;
    return rtn;
}

Result_Bool_String glimage_stbi_write_png(glimage_bindings_Image image, String filename) {
    Result_Bool_String rtn;
    rtn.val.Ok = (struct Ok_Bool_String*) malloc(sizeof(struct Ok_Bool_String));
    rtn.val.Error = (struct Error_Bool_String*) malloc(sizeof(struct Error_Bool_String));
    Bool isSaved;
    const char * fn = filename.bytes;
    isSaved = (bool) stbi_write_png(fn, image.w, image.h, image.channels, (unsigned char *) image.data.bytes, image.w * image.channels);
    if (isSaved) {
        rtn.tag = E_Ok;
        rtn.val.Ok->value = true;
    } else {
        rtn.tag = E_Error;
        rtn.val.Error->value.bytes = (char*) stbi_failure_reason();
    }
    return rtn;
}