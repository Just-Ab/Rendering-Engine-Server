// #ifndef MODEL_H
// #define MODEL_H

// #include <assimp/Importer.hpp>
// #include <assimp/scene.h>
// #include <assimp/postprocess.h>

// #include <Algebra/glm/glm.hpp>

// #include <Rendering/Mesh.h>

// #ifndef TEXTURELOADER_H
// #include <Rendering/TextureLoader.h>
// #endif

// #include <unordered_map>
// class Model
// {
// private:
//     struct StringHash {
//         size_t operator()(const std::string& str) const {
//             return std::hash<std::string>()(str);
//         }
//     };

//     struct StringEqual {
//         bool operator()(const std::string& a, const std::string& b) const {
//             return a == b;
//         }
//     };

//     std::vector<Mesh> meshes;
//     std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type,TextureTypes textureType);

//     std::vector<Attribute> vertexAttributes,instanceAttributes;

//     glm::mat4 transformation;
//     glm::vec3 position=glm::vec3(1.0f),scale=glm::vec3(1.0f);
//     glm::vec4 rotation=glm::vec4(0.0f,glm::vec3(1.0f));

//     std::string directory;

//     std::unordered_map<std::string,Texture,StringHash,StringEqual> texturesLoaded;


//     void loadModel(std::string path);
//     void processNode(aiNode *node, const aiScene *scene);
//     Mesh processMesh(aiMesh *mesh, const aiScene *scene);

// public:
//     Model(std::string path,glm::vec3 position=glm::vec3(1.0f));
    
//     void defineVertexAttributes(Attribute attribute);
//     void defineVertexAttributes(std::vector<Attribute> attributes);

//     void defineInstanceAttributes(Attribute attribute);
//     void defineInstanceAttributes(std::vector<Attribute> attributes);

//     void setPosition(const float x,const float y,const float z);
//     void setPosition(glm::vec3 _position);

//     void setRotation(const float angle,const float x,const float y,const float z);
//     void setRotation(glm::vec4 _axis);


//     void setScale(const float x,const float y,const float z);
//     void setScale(glm::vec3 _scale);



//     void draw(Shader &Shader);
// };


// #endif