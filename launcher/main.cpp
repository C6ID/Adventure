#include <adventure.h>
#include <core/engine.h>

int main(int argc, char * argv[])
{
    SharedPtr<Engine> engine = Adventure::createEngine();
    engine->fireUp();

    while (engine->isRunning()) {
        engine->step();
    }

    return 0;
}
