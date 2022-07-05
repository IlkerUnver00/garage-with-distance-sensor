
import processing.serial.*;
Serial myPort;
String val;
char ent;
int i=0,a=0,k=0;
int islem ;
void setup(){
  size(1200,800);
  myPort = new Serial(this,"/dev/cu.usbmodem141101",9600);
 
}
void draw(){
   if ( myPort.available() > 0) 
  {  // If data is available,
  val = myPort.readStringUntil('\n');
  ent = val.charAt(0);
  println(val);
    println(ent);
  println(islem);
  if(ent == '1'){
   islem = 2;
  }
  else{
   islem = 1; 
  }
  println(val);
    println(ent);
  println(islem);
  }
  
  background(21,76,121);  /* arka plan rengi */
  
  strokeWeight(0);  /* led rengi */
  fill(200,200,200);
  ellipse(950,150,130,130);
  
  strokeWeight(0);
  fill(226,135,67);  /* kapı rengi */
  rect(306,206,440,390);
  
  stroke(170,170,170); /* çubukların rengi */
  strokeWeight(10);
  line(300,200,300,600);
  line(750,200,750,600);
  line(300,200,750,200);
  

  if(islem == 1){

           a=0;
           strokeWeight(0);
           fill(226,135,67);  /* kapı rengi */
           rect(306,206,440,390);
  
           fill(169,194,199); /* iç rengi */
           for(k=0;k<400;k++){
             rect(306,596,440,-i);
           }
           strokeWeight(0);  /* led rengi */
           fill(0,200,0);
           ellipse(950,150,130,130);
  
            stroke(170,170,170); /* çubukların rengi */
            strokeWeight(10);
            line(300,200,300,600);
            line(750,200,750,600);
            line(300,200,750,200);
  
            while(i!=391){
              i++;
              break;
              }
  }
  
    else if(islem == 2){  /* kapı kapanır */
            i=0;
           strokeWeight(0);
           fill(169,194,199);  /* iç rengi */
           rect(306,206,440,390);
  
           fill(226,135,67); /* kapı rengi */
           for(k=0;k<400;k++){
             rect(306,205,440,a);    
           }
           strokeWeight(0);  /* led rengi */
           fill(200,0,0);
           ellipse(950,150,130,130);
  
            stroke(170,170,170); /* çubukların rengi */
            strokeWeight(10);
            line(300,200,300,600);
            line(750,200,750,600);
            line(300,200,750,200);
            while(a!=391){
              a++;
              break;
            }
}
}
