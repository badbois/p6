#include "RectRenderer.h"
#include <array>

namespace p6 {
namespace details {

RectRenderer::RectRenderer()
{
    // VAO
    glBindVertexArray(*_vao);
    // VBO
    const std::array<float, 8> vertices = {
        -.5f, -.5f,
        -.5f, +.5f,
        +.5f, +.5f,
        +.5f, -.5f};
    const auto vertices_size_in_bytes = vertices.size() * sizeof(float);
    glBindBuffer(GL_ARRAY_BUFFER, *_vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices_size_in_bytes, nullptr, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, vertices_size_in_bytes, vertices.data());
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, false, 0, 0);
    // IBO
    const std::array<GLuint, 6> indices = {
        0, 1, 2,
        0, 2, 3};
    const auto indices_size_in_bytes = indices.size() * sizeof(GLuint);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *_ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_size_in_bytes, nullptr, GL_STATIC_DRAW);
    glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, indices_size_in_bytes, indices.data());
}

void RectRenderer::render() const
{
    glBindVertexArray(*_vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

} // namespace details
} // namespace p6