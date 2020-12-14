#version 330
uniform mat4 mvpMatrix; // Matriz MVP
in vec4 vertexPosition; // Entrada de la posición del vértice
out vec4 vertexColor; // Salida del color del vértice

void main() {
	gl_Position = mvpMatrix * vertexPosition; // Modifica la matriz MVP
	vertexColor = vec4(1.0f, 0.0f, 0.0f, 1.0f); // Color del vértice
}
