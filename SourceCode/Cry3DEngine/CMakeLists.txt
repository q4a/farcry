project(Cry3DEngine)

add_definitions(-D_USRDLL -DCRY3DENGINE_EXPORTS)

set(SRC_FILES
    "3DEngine.cpp"
    "3DEngineLight.cpp"
    "3DEngineLoad.cpp"
    "3DEngineRender.cpp"
    "3DEngineScreenEffects.cpp"
    "BasicArea.cpp"
    "Brush.cpp"
    "BrushLM.cpp"
    "cbuffer.cpp"
    "Cry3DEngine.cpp"
    "CryStaticModel.cpp"
    "CVars.cpp"
    "Decal.cpp"
    "DecalManager.cpp"
    "detail_grass.cpp"
    "File.cpp"
    "Geom.cpp"
    "Helper.cpp"
    "Light.cpp"
    "LightMan.cpp"
    "LMSerializationManager2.cpp"
    "MatMan.cpp"
    "Meshidx.cpp"
    "Node.cpp"
    "ObjMan.cpp"
    "ObjManDraw.cpp"
    "ObjManDrawEntity.cpp"
    "ObjManFar.cpp"
    "ObjManShadows.cpp"
    "ObjManStreaming.cpp"
    "particle.cpp"
    "ParticleEffect.cpp"
    "ParticleEmitter.cpp"
    "partman.cpp"
    "partpolygon.cpp"
    "rain.cpp"
    "SpriteManager.cpp"
    "StatObjCompiler.cpp"
    "StatObjConstr.cpp"
    "StatObjFar.cpp"
    "StatObjLoad.cpp"
    "StatObjPhys.cpp"
    "StatObjRend.cpp"
    "StatObjSerialize.cpp"
    "StatObjShadow.cpp"
    "StatObjShadowVolumes.cpp"
    "StatObjStream.cpp"
    "StdAfx.cpp"
    "StencilShadowConnectivityBuilder.cpp"
    "StencilShadowEdgeDetector.cpp"
    "terrain.cpp"
    "terrain_damage.cpp"
    "terrain_det_tex.cpp"
    "terrain_hmap.cpp"
    "terrain_init.cpp"
    "terrain_light.cpp"
    "terrain_load.cpp"
    "terrain_render.cpp"
    "terrain_sector.cpp"
    "terrain_sector_beach.cpp"
    "terrain_sector_render.cpp"
    "terrain_sector_tex.cpp"
    "terrain_tex_pool.cpp"
    "terrain_water_quad.cpp"
    "terran_edit.cpp"
    "Vegetation.cpp"
    "VisAreaMan.cpp"
    "VisAreas.cpp"
    "WaterVolumes.cpp"
)

add_library(${PROJECT_NAME} SHARED ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/SourceCode/CryCommon
)

target_link_libraries(${PROJECT_NAME})
