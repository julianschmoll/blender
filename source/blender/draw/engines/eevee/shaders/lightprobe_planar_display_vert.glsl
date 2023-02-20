
#pragma BLENDER_REQUIRE(common_view_lib.glsl)

void main()
{
  worldPosition = (probe_mat * vec4(-pos.x, pos.y, 0.0, 1.0)).xyz;
  gl_Position = ProjectionMatrix * (ViewMatrix * vec4(worldPosition, 1.0));
  probeIdx = probe_id;
}
