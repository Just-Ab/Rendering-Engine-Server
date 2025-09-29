
#include <Rendering/TextureLoader.h>

        unsigned int TextureLoader::loadTexture2D(std::string path){
            //create id container
            unsigned int textureID;
            //create characteristic containers
            int height,width,nrchannel;
            //generate a texture id
            glGenTextures(1,&textureID);
            //bind texture for usage
            glBindTexture(GL_TEXTURE_2D,textureID);
            //flip texture when loaded to correct orientation
            stbi_set_flip_vertically_on_load(true);
            //load the image data
            unsigned char*data = stbi_load(path.c_str(),&width,&height,&nrchannel,0);

            if (!data){
                std::cout<<"ERR::LOADING::IMG!"<<std::endl;
            }
            //capture image format
            GLenum format;

            if (nrchannel == 1) format = GL_RED;
            else if (nrchannel == 3) format = GL_RGB;
            else if (nrchannel == 4) format = GL_RGBA;
            else{
                std::cout<<"ERR::FORMATTING::IMG!"<<std::endl;
            }
            //generate texture and set the data on the currently bound texture object
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            //exception for grayscale
            if (format == GL_RED) {
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_R, GL_RED);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_G, GL_RED);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_SWIZZLE_B, GL_RED);
            }
            //additional optional setting
            glGenerateMipmap(GL_TEXTURE_2D);
            //set filter method
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            //free data loaded
            stbi_image_free(data);
            //unbind
            glBindTexture(GL_TEXTURE_2D,0);
            return textureID;
        }


        unsigned int TextureLoader::loadCubeMap(std::vector<std::string> &paths){
            unsigned int textureID;
            int width,height,nrchannel;

            glGenTextures(1,&textureID);
            glBindTexture(GL_TEXTURE_CUBE_MAP,textureID);


            for (unsigned int i = 0; i < 6; i++)
            {
                stbi_set_flip_vertically_on_load(false);
                unsigned char* data = stbi_load(paths[i].c_str(),&width,&height,&nrchannel,0);
                if(!data){
                    std::cout<<"ERROR::LOADING::TEXTURE!"<<std::endl;
                }
                glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X+i,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);  
                stbi_image_free(data);

            }
            glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
            glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

            glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_WRAP_R,GL_CLAMP_TO_EDGE);
            return textureID;
        }


        unsigned int TextureLoader::generateTexture(unsigned int width,unsigned int height,GLenum internalFormat,GLenum format,GLenum contentType){
            unsigned int textureID;
            glGenTextures(1,&textureID);
            glBindTexture(GL_TEXTURE_2D,textureID);
            glTexImage2D(GL_TEXTURE_2D,0,internalFormat,width,height,0,format,contentType,NULL);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
             
            return textureID;
        }

