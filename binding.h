#ifdef __cplusplus
extern "C" {
#endif


void go_recv_cb(const char* msg, void* data);

struct worker_s;
typedef struct worker_s worker;
typedef void (*worker_recv_cb)(const char* msg, void* data);

const char* worker_version();

void v8_init();

worker* worker_new(worker_recv_cb cb, void* data);

// returns nonzero on error
// get error from worker_last_exception
int worker_load(worker* w, char* name_s, char* source_s);

const char* worker_last_exception(worker* w);

int worker_send(worker* w, const char* msg);

#ifdef __cplusplus
} // extern "C"
#endif
