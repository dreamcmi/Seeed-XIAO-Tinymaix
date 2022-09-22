#include "tinymaix.h"

#define TEST_MNIST (1)
// #define TEST_CIFAR (1)


#if TEST_MNIST
#include "mnist_valid_q.h"
uint8_t pic[28*28]={
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,116,125,171,255,255,150, 93,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,169,253,253,253,253,253,253,218, 30,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,169,253,253,253,213,142,176,253,253,122,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0, 52,250,253,210, 32, 12,  0,  6,206,253,140,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0, 77,251,210, 25,  0,  0,  0,122,248,253, 65,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0, 31, 18,  0,  0,  0,  0,209,253,253, 65,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,117,247,253,198, 10,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 76,247,253,231, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,253,253,144,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,176,246,253,159, 12,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 25,234,253,233, 35,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,198,253,253,141,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0, 78,248,253,189, 12,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0, 19,200,253,253,141,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,134,253,253,173, 12,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,248,253,253, 25,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,248,253,253, 43, 20, 20, 20, 20,  5,  0,  5, 20, 20, 37,150,150,150,147, 10,  0,
  0,  0,  0,  0,  0,  0,  0,  0,248,253,253,253,253,253,253,253,168,143,166,253,253,253,253,253,253,253,123,  0,
  0,  0,  0,  0,  0,  0,  0,  0,174,253,253,253,253,253,253,253,253,253,253,253,249,247,247,169,117,117, 57,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,118,123,123,123,166,253,253,253,155,123,123, 41,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
};
#define IMG_L 28
#define IMG_CH 1
#define CLASS_NUM (10)
char* labels[CLASS_NUM] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

#elif TEST_CIFAR
#include "cifar10_q.h"
#include "pic2.h"
#define IMG_L 32
#define IMG_CH 3
#define CLASS_NUM 10
char* labels[CLASS_NUM] = { "airplane", "automobile", "bird", "cat", "deer", "dog", "frog", "hrose", "ship", "truck" };

#else
#error "please select MNIST or CIFAR"
#endif

static tm_err_t layer_cb(tm_mdl_t* mdl, tml_head_t* lh) {  //dump middle result
  int h = lh->out_dims[1];
  int w = lh->out_dims[2];
  int ch = lh->out_dims[3];
  mtype_t* output = TML_GET_OUTPUT(mdl, lh);
#if 0
    Serial1.printf("Layer %d callback ========\n", mdl->layer_i);
    for(int y=0; y<h; y++){
        Serial1.printf("[");
        for(int x=0; x<w; x++){
            Serial1.printf("[");
            for(int c=0; c<ch; c++){
#if TM_MDL_TYPE == TM_MDL_FP32
                Serial1.printf("%.3f,", output[(y*w+x)*ch+c]);
#else
                Serial1.printf("%.3f,", TML_DEQUANT(lh,output[(y*w+x)*ch+c]));
#endif
            }
            Serial1.printf("],");
        }
        Serial1.printf("],\n");
    }
    Serial1.printf("\n");
#endif
  return TM_OK;
}

static void parse_output(tm_mat_t* outs) {
  tm_mat_t out = outs[0];
  float* data = out.dataf;
  float maxp = 0;
  int maxi = -1;
  for (int i = 0; i < CLASS_NUM; i++) {
    Serial1.printf("%d: %.3f\n", i, data[i]);
    if (data[i] > maxp) {
      maxi = i;
      maxp = data[i];
    }
  }
  Serial1.printf("### Predict output is: Class %d, Lable %s, prob %.3f\n", maxi, labels[maxi], maxp);
  return;
}

static uint8_t mdl_buf[MDL_BUF_LEN];

void setup() {
  Serial1.begin(115200);

  /* Begin TinyMaix */
  TM_DBGT_INIT();
  Serial1.printf("mnist demo\n");
  tm_mdl_t mdl;

  // for (int i = 0; i < 28 * 28; i++) {
  //   Serial1.printf("%3d,", pic[i]);
  //   if (i % 28 == 27)
  //     Serial1.printf("\n");
  // }

  tm_mat_t in_uint8 = { 3, IMG_L, IMG_L, IMG_CH, (mtype_t*)pic };
  tm_mat_t in = { 3, IMG_L, IMG_L, IMG_CH, NULL };
  tm_mat_t outs[1];
  tm_err_t res;
  tm_stat((tm_mdlbin_t*)mdl_data);

  res = tm_load(&mdl, mdl_data, mdl_buf, layer_cb, &in);
  if (res != TM_OK) {
    Serial1.printf("tm model load err %d\n", res);
    goto end;
  }

#if (TM_MDL_TYPE == TM_MDL_INT8) || (TM_MDL_TYPE == TM_MDL_INT16)
  res = tm_preprocess(&mdl, TMPP_UINT2INT, &in_uint8, &in);
#else
  res = tm_preprocess(&mdl, TMPP_UINT2FP01, &in_uint8, &in);
#endif
  TM_DBGT_START();
  res = tm_run(&mdl, &in, outs);
  TM_DBGT("tm_run");
  if (res == TM_OK) {
#ifndef TEST_MBNET
    parse_output(outs);
#endif
  } else
    Serial1.printf("tm run error: %d\n", res);
  tm_unload(&mdl);

end:
  while (1) {
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}