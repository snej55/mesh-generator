#include "src/app.h"
#include "src/terrain.h"

int main()
{
    // initialization
    App app{640, 640, "OpenGL window"};
    app.enableDepthTesting();
    app.setCameraEnabled(true);

    const Shader terrainShader {"data/shaders/heightMap.vert", "data/shaders/heightMap.frag"};
    Terrain terrain{};
    terrain.load("data/images/iceland_heightmap.png");

    // main loop
    while (!app.shouldClose())
    {
        // for wireframe rendering
        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        app.handleInput();
        
        app.clear();

        terrain.render(terrainShader, app.getPerspectiveMatrix(), app.getViewMatrix(), glm::mat4{1.0f});

        app.tick();
    }

    // clean up
    app.close();

    return 0;
}
