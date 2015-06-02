#version 150

uniform vec4 a;
uniform vec4 b;
uniform vec4 c;
uniform vec4 d;

uniform float windowWidth;
uniform float width;
uniform float margin;
out vec4 color;

void main(){
	float t = (gl_FragCoord.x - margin) / width;
	color = a + b * cos(6.28318 * (c * t + d));
}