attribute vec3 a_posL;
attribute vec3 a_color;
varying vec3 v_color;
uniform mat4 u_rotZ;
uniform mat4 u_view;
uniform mat4 u_persp;

attribute vec2 a_uv;
varying vec2 v_uv;

void main()
{
	vec4 posL = vec4(a_posL, 1.0);
	v_uv = a_uv;
	gl_Position = u_persp * u_view * posL;
}
   