// #include <Rendering/Model.h>




//     Model::Model(std::string path,glm::vec3 position){
//         loadModel(path);
//         setPosition(position);
//     }


//     void Model::defineVertexAttributes(Attribute attribute){
//         for (unsigned int i = 0; i < meshes.size(); i++)
//         {
//             meshes[i].defineVertexAttributes(attribute);
//         }    
//     }

//     void Model::defineVertexAttributes(std::vector<Attribute> attributes){
//         for (unsigned int i = 0; i < meshes.size(); i++)
//         {
//             meshes[i].defineVertexAttributes(attributes);
//         }    
//     }

//     void Model::defineInstanceAttributes(Attribute attribute){
//         for (unsigned int i = 0; i < meshes.size(); i++)
//         {
//             meshes[i].defineInstanceAttributes(attribute);
//         }
          
//     }

//     void Model::defineInstanceAttributes(std::vector<Attribute> attributes){
//         for (unsigned int i = 0; i < meshes.size(); i++)
//         {
//             meshes[i].defineInstanceAttributes(attributes);
//         }    
//     }



//     //**LOADING THE MODEL */
//     void Model::loadModel(std::string path){
//         Assimp::Importer importer;
//         const aiScene *scene = importer.ReadFile(path,aiProcess_Triangulate|aiProcess_FlipUVs|aiProcess_OptimizeMeshes);
    
//         if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) 
//         {
//             std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
//             return;
//         }

//         directory = path.substr(0,path.find_last_of('/'));

//         processNode(scene->mRootNode,scene);
    
    
    
//     }

//     void Model::processNode(aiNode *node, const aiScene *scene){
//         //fetching all mesh indices in a node;
//         for (unsigned int i = 0; i < node->mNumMeshes; i++)
//         {
//             //get mesh mesh object from the scene
//             aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
//             //push the mesh in the set of meshes after processing
//             meshes.push_back(processMesh(mesh,scene));
//         }
//         for (unsigned int j = 0; j < node->mNumChildren; j++)
//         {   
//             //recursivly return the unprocessed modes to be processed
//             processNode(node->mChildren[j],scene);
//         }
        
        
//     }

//     Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene){
        
//         //variables to be used in creating the model later
//         std::vector<MeshVertex> vertices;
//         std::vector<unsigned int> indices;
//         std::vector<Texture> textures;

//         //fetch all vertices in a mesh
//         for (unsigned int i = 0; i < mesh->mNumVertices; i++)
//         {
//             MeshVertex vertex;
//             //buffer for vectors with 3 coordinates
//             glm::vec3 vector3;
//             //buffer for vectors with 2 coordinates
//             glm::vec2 vector2;

//             vector3.x = mesh->mVertices[i].x;
//             vector3.y = mesh->mVertices[i].y;
//             vector3.z = mesh->mVertices[i].z;

//             vertex.position = vector3;

//             vector3.x = mesh->mNormals[i].x;
//             vector3.y = mesh->mNormals[i].y;
//             vector3.z = mesh->mNormals[i].z;

//             vertex.normal = vector3;

//             if(mesh->mTextureCoords[0]){
//                 vector2.x = mesh->mTextureCoords[0][i].x;
//                 vector2.y = mesh->mTextureCoords[0][i].y;
//             }
//             else{
//                 vector2.x = 0.0f;
//                 vector2.y = 0.0f;
//             }

//             vertex.texel = vector2;

//             //copy all data to the array
//             vertices.push_back(vertex);
//         }

//         for (unsigned int i = 0; i < mesh->mNumFaces; i++)
//         {
//             aiFace face = mesh->mFaces[i];            
//             for (unsigned int j = 0; j < face.mNumIndices; j++)
//             {
//                 indices.push_back(mesh->mFaces[i].mIndices[j]);
//             }   
//         }

//         if(mesh->mMaterialIndex>0){
//             aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
//             std::vector<Texture> diffuseMap = loadMaterialTextures(material,aiTextureType_DIFFUSE,TextureTypes::DIFFUSE);
//             textures.insert(textures.end(),diffuseMap.begin(),diffuseMap.end());

//             std::vector<Texture> specularMap = loadMaterialTextures(material,aiTextureType_SPECULAR,TextureTypes::SPECULAR);
//             textures.insert(textures.end(),specularMap.begin(),specularMap.end());
//         }
        
//         Mesh result(vertices,indices,textures);

//         result.defineVertexAttributes(vertexAttributes);
//         result.defineInstanceAttributes(instanceAttributes);

//         return result;
//     }

//     std::vector<Texture> Model::loadMaterialTextures(aiMaterial *mat, aiTextureType aiType,TextureTypes textureType)
//     {
//         //return textures container
//         std::vector<Texture> textures;

//         //loop around all textures of a type in the onj file sone are repeaterd
//         for (unsigned int i = 0; i < mat->GetTextureCount(aiType); i++)
//         {
//             //string type of assimp must be used with assimp types such as mVertices,mIndices etc...
//             aiString aiPath;

//             //this function takes a textue type and an index to assign the path to an aiString
//             mat->GetTexture(aiType,i,&aiPath);

//             //convert aistring to C type char*
//             const char* relativePath = aiPath.C_Str();

//             //extend to directory path
//             std::string fullPath = directory+"/"+relativePath;

//             //check for cached texture in texturesLoaded map, if exists return a pair of <path:texture>
//             //remove the next6 lines of code if you want you ram to be filled in 10 seconds
//             auto cached = texturesLoaded.find(fullPath);
//             if (cached != texturesLoaded.end()){
//                 textures.push_back(cached->second);
//                 continue;
//             }

//             //create a texture holder

//             //load the texture image & transfer data
//             TextureLoader textureLoader;
//             Texture texture = textureLoader.loadTexture2D(fullPath);
//             texture.TYPE = textureType;

//             //add to the return vector
//             textures.push_back(texture);

//             //add to loaded textures
//             texturesLoaded[fullPath] = texture;
            
//         }
//         return textures;
//     }
//     //**LOADING THE MODEL END*/

//     void Model::setPosition(const float x,const float y,const float z){
//         position = glm::vec3(x,y,z);
//     }

//     void Model::setPosition(glm::vec3 _position){
//         position = _position;
//     }

//     void Model::setRotation(const float angle,float x,float y,float z){
//         rotation = glm::vec4(angle,x,y,z);
//     }

//     void Model::setRotation(glm::vec4 _rotation){
//         rotation = _rotation;
//     }

//     void Model::setScale(float xScalar,float yScalar,float zScalar){
//         scale = glm::vec3(xScalar,yScalar,zScalar);
//     }

//      void Model::setScale(glm::vec3 _scale){
//         scale = _scale;
//     }   


//     void Model::draw(Shader &shader){
//         transformation = glm::translate(glm::mat4(1.0f),position);
//         transformation = glm::rotate(transformation,glm::radians(rotation.x),glm::vec3(rotation.y,rotation.z,rotation.w));
//         transformation = glm::scale(transformation,scale);
//         std::vector<MeshDataInstance> data = {{transformation}};
//         for (unsigned int i = 0; i < meshes.size(); i++)
//         {   
//             meshes[i].draw(shader,data);
//         }
//         for (unsigned int i = 0; i < 32; i++)
//         {
//             glActiveTexture(GL_TEXTURE0+i);
//             glBindTexture(GL_TEXTURE_2D,0);
//         }
        
//     }
