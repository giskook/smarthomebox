
#define CERECONNSOCKET "R"
#define CERECONNSERIAL "S"
#define CEHEART "H"

struct cetimer; 
struct cetimer * cetimer_create(unsigned int nextvalue, unsigned int interval, int wfd);
void cetimer_start(struct cetimer * timer);


