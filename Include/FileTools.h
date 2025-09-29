#ifndef FILETOOLS_H
#define FILETOOLS_H

    #include <iostream>

    char* readFile(const char*path);

    class FileSystem {
        
        public:
            static std::string getPath(const std::string& relativePath);
    };
    
#endif