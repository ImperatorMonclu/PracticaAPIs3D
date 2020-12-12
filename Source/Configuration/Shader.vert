attribute vec3 vPos;
varying vec3 fColor;
uniform mat4 mvpMatrix;

void main() {
	gl_Position = mvpMatrix * vec4(vPos, 1);
	fColor = vec3(1, 1, 1);
}
