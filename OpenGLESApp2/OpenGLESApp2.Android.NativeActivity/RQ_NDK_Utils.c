#include "RQ_NDK_Utils.h"


int64_t timespec2ms64(struct timespec *pt) {
 return (((int64_t)(*pt).tv_sec) * 1000000000LL + (*pt).tv_nsec) / 1000000;
}
int64_t timespec2us64(struct timespec *pt) {
 return (((int64_t)(*pt).tv_sec) * 1000000000LL + (*pt).tv_nsec) / 1000;
}


//User free to free passed buffer
void *getAssetFileToBuffer(android_app* state, const char *pFileName, size_t &size){
 void *pBuffer = NULL;

 ANativeActivity* activity = state->activity;
 JNIEnv* env = 0;

 activity->vm->AttachCurrentThread(&env, NULL);

 jclass activity_class = env->GetObjectClass(activity->clazz);

 jmethodID activity_class_getAssets = env->GetMethodID(activity_class, "getAssets", "()Landroid/content/res/AssetManager;");
 jobject asset_manager = env->CallObjectMethod(activity->clazz, activity_class_getAssets); // activity.getAssets();
 jobject global_asset_manager = env->NewGlobalRef(asset_manager);

 AAssetManager *pAssetManager = AAssetManager_fromJava(env, global_asset_manager);


 activity->vm->DetachCurrentThread();


 android_fopen_set_asset_manager(pAssetManager);

 FILE* android_file = android_fopen(pFileName);
 fseek(android_file, 0L, SEEK_END);
 size = ftell(android_file);
 rewind(android_file);
 pBuffer = malloc(size + 1);
 fread(pBuffer, size, 1, android_file);
 fclose(android_file);

 return pBuffer; 
}

void CopyFloat16ToMatrix(MatrixXf &mf, float *mfa) {
 for (int cnt = 0; cnt < 16; cnt++) {
  mf(cnt) = mfa[cnt];
 }
}
void CopyMatrix16ToFloat(MatrixXf &mf, float *mfa) {
 for (int cnt = 0; cnt < 16; cnt++) {
  mfa[cnt] = mf(cnt);
 }
}



