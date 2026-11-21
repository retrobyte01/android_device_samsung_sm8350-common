#include "ALooper.h"

// Samsung's libsensorndkbridge gives the camera its own loopers instead of
// the global ALooper_prepare one (libsensorlistener, libvdis_core, libhypermotion_core)
extern "C" {

ALooper* ALooper_forCamera() {
    return new ALooper;
}

int ALooper_pollOnce_camera(ALooper* looper, int timeoutMillis, int* outFd, int* outEvents,
                            void** outData) {
    return looper->pollOnce(timeoutMillis, outFd, outEvents, outData);
}

void ALooper_release_forCamera(ALooper* looper) {
    delete looper;
}

}
