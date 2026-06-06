#pragma once

namespace Config
{
namespace Window
{
    constexpr const char* GAME_NAME = "Snake";
    constexpr int WIDTH = 800;
    constexpr int HEIGHT = 600;
    constexpr int FRAMERATE_LIMIT = 60;
}

namespace Gameplay
{
    constexpr int START_DIRECTION = 0;
    constexpr float SNAKE_STEPS_PER_SECOND = 4.f;
    constexpr float SNAKE_STEP_INTERVAL = 1.f / SNAKE_STEPS_PER_SECOND;
}

namespace Objects
{
    constexpr int SEGMENT_WIDTH = 40;
}
}
