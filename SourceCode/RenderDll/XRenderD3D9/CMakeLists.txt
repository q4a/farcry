project(XRenderD3D9)

add_definitions(-DENABLE_FRAME_PROFILER -DPROC_INTEL -DDIRECT3D9 -D_USRDLL -DXRENDERD3D9_EXPORTS -DDO_RENDERLOG -DDO_RENDERSTATS -D_RENDERER)
if (${ARCH_TYPE} STREQUAL "x86")
    add_definitions(-DDO_ASM)
endif()

if (MSVC)
	add_compile_options(/SAFESEH:NO)
endif()

set(SRC_FILES
    "../Common/3DUtils.cpp"
    "../Common/CRT.cpp"
    "../Common/EvalFuncs_C.cpp"
    "../Common/EvalFuncs_RE.cpp"
    "../Common/LeafBufferCreate.cpp"
    "../Common/LeafBufferRender.cpp"
    "../Common/LeafBufferSerialize.cpp"
    "../Common/LightMaterial.cpp"
    "../Common/Names.cpp"
    "../Common/NvTriStrip/NvTriStrip.cpp"
    "../Common/NvTriStrip/NvTriStripObjects.cpp"
    "../Common/pip_addons.cpp"
    "../Common/RendElements/CRE2DQuad.cpp"
    "../Common/RendElements/CREBeam.cpp"
    "../Common/RendElements/CREClientPoly.cpp"
    "../Common/RendElements/CREClientPoly2D.cpp"
    "../Common/RendElements/CREDummy.cpp"
    "../Common/RendElements/CREFlares.cpp"
    "../Common/RendElements/CREFlashBang.cpp"
    "../Common/RendElements/CREGlare.cpp"
    "../Common/RendElements/CREHDRProcess.cpp"
    "../Common/RendElements/CREOcean.cpp"
    "../Common/RendElements/CREOcLeaf.cpp"
    "../Common/RendElements/CREOclusionQuery.cpp"
    "../Common/RendElements/CREParticleSpray.cpp"
    "../Common/RendElements/CREPolyBlend.cpp"
    "../Common/RendElements/CREPolyMesh.cpp"
    "../Common/RendElements/CREPrefabGeom.cpp"
    "../Common/RendElements/CREScreenProcess.cpp"
    "../Common/RendElements/CREShadowMap.cpp"
    "../Common/RendElements/CRESky.cpp"
    "../Common/RendElements/CRETempMesh.cpp"
    "../Common/RendElements/CRETerrainSector.cpp"
    "../Common/RendElements/CRETriMeshShadow.cpp"
    "../Common/RendElements/FFT_SSE.cpp"
    "../Common/RendElements/RendElement.cpp"
    "../Common/Renderer.cpp"
    "../Common/ResFile.cpp"
    "../Common/Shaders/Parser.cpp"
    "../Common/Shaders/ShaderComponents.cpp"
    "../Common/Shaders/ShaderCore.cpp"
    "../Common/Shaders/ShaderParse.cpp"
    "../Common/Shaders/ShaderScript.cpp"
    "../Common/Shaders/ShaderTemplate.cpp"
    "../Common/Textures/Image/BmpImage.cpp"
    "../Common/Textures/Image/CImage.cpp"
    "../Common/Textures/Image/DDSImage.cpp"
    "../Common/Textures/Image/inv_cmap.cpp"
    "../Common/Textures/Image/JpgImage.cpp"
    "../Common/Textures/Image/PcxImage.cpp"
    "../Common/Textures/Image/Quantize.cpp"
    "../Common/Textures/Image/TgaImage.cpp"
    "../Common/Textures/TexMan.cpp"
    "../Common/Textures/TexManShadows.cpp"
    "../Common/Textures/TexManStreaming.cpp"
    "../RenderPCH.cpp"
    "D3DCGPShader.cpp"
    "D3DCGVProgram.cpp"
    "D3DEnumeration.cpp"
    "D3DFont.cpp"
    "D3DHDRRender.cpp"
    "D3DLog.cpp"
    "D3DRenderRE.cpp"
    "D3DRendPipeline.cpp"
    "D3DREOcean.cpp"
    "D3DScreenRender.cpp"
    "D3DShaders.cpp"
    "D3DShadows.cpp"
    "D3DSprites.cpp"
    "D3DSystem.cpp"
    "D3DTextures.cpp"
    "D3DTexturesStreaming.cpp"
    "D3DVertBuffer.cpp"
    "DriverD3D9.cpp"
)

if (${ARCH_TYPE} STREQUAL "x86")
    set(ARCH_LIBS
        ijl15.lib
        nvDXTlib.lib
    )
    set(DXLIB_PATH ${CMAKE_SOURCE_DIR}/SourceCode/RenderDll/Dx9Sdk/Lib)
else() #x64
    set(ARCH_LIBS)
    set(DXLIB_PATH ${CMAKE_SOURCE_DIR}/SourceCode/RenderDll/Dx9Sdk/Lib64)
    list(APPEND SRC_FILES
    "../Common/Textures/Image/jpeg6/jcomapi.cpp"
    "../Common/Textures/Image/jpeg6/jdapimin.cpp"
    "../Common/Textures/Image/jpeg6/jdapistd.cpp"
    "../Common/Textures/Image/jpeg6/jdatasrc.cpp"
    "../Common/Textures/Image/jpeg6/jdcoefct.cpp"
    "../Common/Textures/Image/jpeg6/jdcolor.cpp"
    "../Common/Textures/Image/jpeg6/jddctmgr.cpp"
    "../Common/Textures/Image/jpeg6/jdhuff.cpp"
    "../Common/Textures/Image/jpeg6/jdinput.cpp"
    "../Common/Textures/Image/jpeg6/jdmainct.cpp"
    "../Common/Textures/Image/jpeg6/jdmarker.cpp"
    "../Common/Textures/Image/jpeg6/jdmaster.cpp"
    "../Common/Textures/Image/jpeg6/jdpostct.cpp"
    "../Common/Textures/Image/jpeg6/jdsample.cpp"
    "../Common/Textures/Image/jpeg6/jdtrans.cpp"
    "../Common/Textures/Image/jpeg6/jerror.cpp"
    "../Common/Textures/Image/jpeg6/jfdctflt.cpp"
    "../Common/Textures/Image/jpeg6/jidctflt.cpp"
    "../Common/Textures/Image/jpeg6/jmemmgr.cpp"
    "../Common/Textures/Image/jpeg6/jmemnobs.cpp"
    "../Common/Textures/Image/jpeg6/jutils.cpp"
    )
endif()

add_library(${PROJECT_NAME} SHARED ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/SourceCode/CryCommon
    ${CMAKE_SOURCE_DIR}/SourceCode/RenderDll
    ${CMAKE_SOURCE_DIR}/SourceCode/RenderDll/Dx9Sdk/Include
    ${CMAKE_SOURCE_DIR}/Externals/SDL/include
)

target_link_directories(${PROJECT_NAME} PRIVATE
    ${DXLIB_PATH}
    Libraries
)

set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /NODEFAULTLIB:libcp.lib /NODEFAULTLIB:LIBC.lib")

target_link_libraries(${PROJECT_NAME} PRIVATE
    d3d9.lib
    d3dx9.lib
    DXErr.lib
    cg.lib
    cgD3D9.lib
    ${ARCH_LIBS}
    winmm.lib

    SDL2
)
