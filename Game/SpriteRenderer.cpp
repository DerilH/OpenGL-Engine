#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(std::string textureName, glm::vec3 position, glm::vec3 size, float rotation, glm::vec3 rotationAxis)
{
	texture = ResourceManager::Textures[textureName];

    this->position = position;
    this->size = size;
    this->rotationAxis = rotationAxis;
    this->rotation = rotation;

    this->modelMatrix.SetScaleMat4(this->size);
    this->modelMatrix.SetTranslationMat4(this->position);

    unsigned int VBO;
    float vertices[] = {
       0.0f, 1.0f, 0.0f, 1.0f,
       1.0f, 0.0f, 1.0f, 0.0f,
       0.0f, 0.0f, 0.0f, 0.0f,

       0.0f, 1.0f, 0.0f, 1.0f,
       1.0f, 1.0f, 1.0f, 1.0f,
       1.0f, 0.0f, 1.0f, 0.0f
    };


    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(this->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
}

void SpriteRenderer::render()
{
    RenderPipeline::shader.use();
    RenderPipeline::shader.SetMatrix4("model", this->modelMatrix.matrix);
    RenderPipeline::shader.SetMatrix4("projection", ProjectionMatrix::Perspective());
    //RenderPipeline::shader.SetMatrix4("view", this->viewMatrix.matrix);
    RenderPipeline::shader.setInt("image", 0);

    glActiveTexture(GL_TEXTURE0);
    texture.Bind();


    glBindVertexArray(VAO);
    RenderPipeline::shader.use();
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}
