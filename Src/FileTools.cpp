    #include <FileTools.h>
    #include <filesystem>
    #include <cstdint>
    
    char* readFile(const char*path){
        FILE*file;
        file = fopen(path,"rb");
        if (!file){
            std::cout<<"ERRLoadingFILE!: "<<path<<std::endl;
            return NULL;
        }
        uint64_t fileSize;
        fseek(file,0,SEEK_END);
        fileSize = ftell(file);
        if (fileSize<0){
            std::cout<<"ERRTailingFILE!"<<std::endl;
            fclose(file);
            return NULL;
        }

        char *buffer = (char*)malloc(fileSize+1);

        fseek(file,0,SEEK_SET);
        size_t bytes_read = fread(buffer,sizeof(char),fileSize,file);
        if (!buffer){
            std::cout<<"ERRFillingBUFFER!"<<std::endl;
            fclose(file);
            return NULL;
        }
        buffer[bytes_read]='\0';
        fclose(file);
        return buffer;
    }

    std::string FileSystem::getPath(const std::string& relativePath) {
        
        std::filesystem::path currentPath = std::filesystem::current_path();
        
        for (int i = 0; i < 5; ++i) {
            std::filesystem::path fullPath = currentPath / relativePath;
            if (std::filesystem::exists(fullPath)) {
                return fullPath.string();
            }
            currentPath = currentPath.parent_path();
        }
                return relativePath;
    }