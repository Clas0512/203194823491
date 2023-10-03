#include <ros/ros.h>
#include "ros/init.h"
#include <std_msgs/String.h>

int main(int ac, char **av) {

  ros::init(ac, av, "publisherScript", 0);
  // Yayınlanacak olan mesaj değişkenini tanımlıyoruz.
  std_msgs::String message;
  // ros::NodeHandle türünden bir değişken tanımlıyoruz.
  ros::NodeHandle nodeHandle;
  // Publisherımızı oluşturuyoruz.
  // ros::Publisher türünden bir değişken tanımlıyoruz.
  ros::Publisher publisher;

  // ros::init methodu ile "publisherScript" adında bir node başlatıyoruz.


  // Bir rate belirliyoruz. Rate, bir durumun saniyede kaç kere çalışacağını
  // kontrol etmek için kullanılan bir araçtır. 2 olarak ayarladığım rate 2 Hz
  // frekansında yayın yapacaktır.
  ros::Rate rateHz(2);


  // Hemen ardından bu publisherı string türünden bir publisher olarak
  // belirleyip bir konu yayınlamaya ayarlıyoruz. Buradaki 1000 sayısı mesaj
  // kuyruğunun kapasite büyüklüğünü ifade ediyor. Yani geçici olarak tutulan
  // maximum mesaj boyutu.
  publisher = nodeHandle.advertise<std_msgs::String>("Anything", 1000);

  // döngünün koşulu olan "ok()" methodu eğer döngü sonlanmadıysa veya ros
  // konusu hala yayındaysa "true" döner ve çalışmaya devam eder.
  while (ros::ok()) {
    message.data = "Selam Millllettt! 101010101!";
    publisher.publish(message);
    rateHz.sleep();
    ros::spinOnce();
  }
}
