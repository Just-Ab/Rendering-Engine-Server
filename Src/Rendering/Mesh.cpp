// #include <Rendering/Mesh.h>


// Mesh::Mesh(std::vector<MeshVertex> _vertices,std::vector<unsigned int> _indices,std::vector<Texture> _textures){
//     vertices = _vertices;
//     indices = _indices;
//     textures = _textures;
//     setup();
// }

// void Mesh::setup(){
//     vao.bind();
//     vbo.setVertices(vertices);
//     EBO ebo(indices);
//     vbo.unBind();
//     vao.unBind();
// }

// void Mesh::draw(Shader& shader,unsigned int instances){
//     shader.activate();
//     vao.bind();
//     glDrawElementsInstanced(GL_TRIANGLES,indices.size(),GL_UNSIGNED_INT,0,instances);
//     vao.unBind();
//     shader.disactivate();
// }

// void Mesh::draw(Shader& shader,std::vector<MeshDataInstance>& instances){
//     shader.activate();
//     vao.bind();
//     instanceVbo.setInstances(instances);
//     for (unsigned int i = 0; i < textures.size(); i++)
//     {
//         if(textures[i].TYPE==TextureTypes::DIFFUSE){
//             glActiveTexture(GL_TEXTURE0+i);
//             glBindTexture(GL_TEXTURE_2D,textures[i].ID);
//             shader.setInt("material.diffuse_texture0",i);
//         }
//         if(textures[i].TYPE==TextureTypes::SPECULAR){
//             glActiveTexture(GL_TEXTURE0+i);
//             glBindTexture(GL_TEXTURE_2D,textures[i].ID);
//             shader.setInt("material.specular_texture0",i);
//         }
//     }
//     glActiveTexture(GL_TEXTURE0);

//     glDrawElementsInstanced(GL_TRIANGLES,indices.size(),GL_UNSIGNED_INT,0,instances.size());
//     vao.unBind();
//     shader.disactivate();
// }




