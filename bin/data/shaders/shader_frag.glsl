#version 150

uniform vec4 a;
uniform vec4 b;
uniform vec4 c;
uniform vec4 d;

uniform vec2 pos;
uniform vec2 dim;
out vec4 color;

vec3 pal(float t, vec3 ac, vec3 bc, vec3 cc, vec3 dc){
	return ac + bc * cos(6.28318 * (cc * t + dc));
}

void main(){
	vec2 p = (gl_FragCoord.xy - pos) / dim;
	vec3 clr = pal(p.x, a.xyz, b.xyz, c.xyz, d.xyz);

	// Shadowing
	clr *= 0.5 + 0.5 * sqrt(4.0 * p.y * (1.0 - p.y));
	// Dithering
	clr += 1.0 / 255.0 * (noise3(gl_FragCoord.x) * 0.5 + 0.5);

	color = vec4(clr, 1.0);
}