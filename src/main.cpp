#include <zip.h>
#include <iostream>
#include <cstring>

int main() {
    zip_t *archive = zip_open("C:\\Users\\korol\\Desktop\\proj\\zipapp\\testfiles\\example.zip", ZIP_CREATE | ZIP_TRUNCATE, nullptr);
    if (!archive) {
        std::cerr << "Failed to create archive!" << std::endl;
        return 1;
    }

    const char *content = "Hello, libzip!";
    zip_source_t *source = zip_source_buffer(archive, content, strlen(content), 0);
    zip_file_add(archive, "hllo.txt", source, ZIP_FL_ENC_UTF_8);

    zip_close(archive);
    std::cout << "Archive created!" << std::endl;
    return 0;
}