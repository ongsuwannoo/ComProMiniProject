<h1 align="center"> 
Ultrascanic
</h1>
<h3 align="center">อุปกรณ์หลักที่ใช้</h3>
1. Ultrasonic Sensor Module (HC-SR04) เป็นตัวส่งสัญญาณอัลตร้าโซนิคออกไปและสะท้อนกลับมา เพื่อจับเวลาแล้วนำมาคำนวนเป็นระยะทาง <br>
2. Servo motor 180 degrees เป็นมอเตอร์ที่สามารถหมุนได้ 180 องศา ควบคุมแบบป้อนกลับ ทำให้ได้ค่าที่ใกล้เคียงกับที่ต้องการ<br>
3. Variable resistor เป็นตัวต้านทานแบบปรับค่าได้ ซึ่งตัวที่จะนำมาใช้ในโปรเจคนี้คือตัว 10k จะคืนค่า 0 - 1023 เพื่อนำไปคำนวนต่อ<br>
4. Arduino uno r3 เป็นบอร์ดตัวหลักของโปรเจคนี้ทำหน้าที่เป็น Microcontroller ของโปรเจคนี้<br>
5. Liquid Crystal Display เป็นจอ lcd ขนาด 16 ตัวอักษร 2 แถว<br>

# Objective
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;โดยปกติแล้วเวลาที่คนเราอยู่ในที่มืดม่านตาของเราจะขยายออกเพื่อเพิ่มรูรับแสงเพื่อที่จะสามารถมองเห็นได้ในที่มืดแต่ว่าก็มีบางคนที่ม่านตาไม่สามารถขยายได้ เช่น คนที่ป็นโรค Night Blindness ทำให้เค้าไม่สามารถมองเห็นในที่มืดได้พวกผมจึงได้ทำโปรเจ็คนี้ขึ้นมาเพื่อให้เค้าสามารถเดินในที่มืดได้โดยที่ไม่ไปชนกับสิ่งของ

# Description 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Mini Project นี้เป็นการนำเสนอ Microcontroller Project โดยตัวหลักที่จะใช้คือ <a href=https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf>HC-SR04</a> ซึ่งเป็นตัวส่งสัญญาณ Ultrasonic (คลื่นความถี่วิทยุ) โดยป้อนไฟให้ขา VCC และ GND โมดูลนี้ มีขาสัญญาณดิจิทัล TRIG (อินพุต) และ ECHO (เอาต์พุต) ที่นำไปเชื่อมต่อกับไมโครคอนโทรลเลอร์ได้ อย่างเช่น Arduino ในการวัดระยะห่างแต่ละครั้ง จะต้องสร้างสัญญาณแบบ Pulse ที่มีความกว้าง (Pulse Width) อย่างน้อย 10 usec ป้อนให้ขา TRIG และหลังจากนั้นให้วัดความกว้างของสัญญาณช่วง HIGH จากขา ECHO ถ้าวัตถุอยู่ใกล้ <b>ความกว้างของสัญญาณ Pulse ที่ได้ก็จะน้อย แต่ถ้าวัตถุอยู่ไกลออกไป ก็จะได้ค่าความกว้างของสัญญาณ Pulse ที่มากขึ้น</b> <br><br>
<h3 align="center">HC-SR04 </h3>
<p align="center"> 
<img src="https://www.piborg.org/image/cache/catalog/freeburn/BURN-0019/DSC_0245-1024x780.jpg" height="300" width="400">
</p>
หลักการทำงานของโมดูล HC-SR04
โมดูล HC-SR04 ใช้สำหรับการวัดระยะห่างด้วยคลื่นอัลตราโซนิค มีสองส่วนหลักคือ ตัวส่งคลื่นที่ทำหน้าที่สร้างคลื่นเสียงออกไปในการวัดระยะแต่ละครั้ง ("Ping") แล้วเมื่อไปกระทบวัตถุหรือสิ่งกีดขวาง คลื่นเสียงถูกสะท้อนกลับมายังตัวรับแล้วประมวลผลด้วยวงจรอิเล็กทรอนิกส์ภายในโมดูล ถ้าจับเวลาในการเดินทางของคลื่นเสียงในทิศทางไปและกลับ และถ้าทราบความเร็วเสียงในอากาศ ก็จะสามารถคำนวณระยะห่างจากวัตถุกีดขวางได้
<br><br><b>- ใช้แรงดันประมาณ +5V </b><br>
<b>- กินกระแสประมาณ 15mA </b><br>
<b>- ช่วงการวัดระยะทาง (measurement range): ประมาณ 2cm - 400cm  </b><br>
<b>- ความกว้างเชิงมุมในการวัด (measuring angle): 15 องศา </b><br>
<b>- ความกว้างของสัญญาณ Pulse สำหรับ Trigger: 10 usec  </b><br>
<b>- ระดับแรงดันลอจิกสำหรัขา TRIG และ ECHO: 5V TTL  </b><br>
<b>- ความแม่นยำ 3mm  </b><br>
<b>- ใช้คลื่นเสียงความถี่ ประมาณ 40kHz  </b><br>
<b>- สูตรการคำนวนระยะทาง<br> 
จาก v = 340 m/s&nbsp;&nbsp;&nbsp;&nbsp;=&nbsp;&nbsp;&nbsp;&nbsp;(340 * 100)/10^6 cm/usec&nbsp;&nbsp;&nbsp;=&nbsp;&nbsp;&nbsp;&nbsp;34/1000 cm/usec <br>
ฉนั้น 2 * d = v * t&nbsp;&nbsp;&nbsp;&nbsp;=&nbsp;&nbsp;&nbsp;&nbsp;d = v * t/2&nbsp;&nbsp;&nbsp;&nbsp;=&nbsp;&nbsp;&nbsp;&nbsp;(17 * t)/1000 cm&nbsp;&nbsp;&nbsp;&nbsp;=&nbsp;&nbsp;&nbsp;&nbsp;(17 * t)/100 mm.&nbsp;&nbsp;&nbsp;&nbsp;=&nbsp;&nbsp;&nbsp;&nbsp;t * 0.034/2 cm.</b><br>
<br><br>
<h3 align="center">Variable Resistor</h3>
<p align="center"> 
<img src="https://hallroad.org/images/thumbnails/913/913/detailed/10/Volume_Type_Variable_Resistor_in_pakistan_Potentiometer_Trimmer_Resistor.jpg" height="300" width="400">
 </p>
 Variable Resistorตัวต้านทานชนิดเปลี่ยนค่าได้ มีแกนหมุนเปลี่ยนค่าความต้านทานคือโวลลุ่ม (Volume) ซึ่งเราได้นำมาใช้ในการปรับความเร็วของเรดาห์
ลักษณะการทำงานของโปรเจคตัวนี้ จะมีตัวอุปกรณ์หลักคือ <br>
<h3 align="center">servo motor 180 degrees</h3>
<p align="center"> 
<img src="https://cdn.instructables.com/FCM/8DKT/IBXMML6A/FCM8DKTIBXMML6A.LARGE.jpg" height="300" width="400">
  </p>
  Servo Motor คือระบบควบคุมที่ประกอบด้วยไฟฟ้าคอนโทรลและเครื่องกล ใช้สำหรับงานที่ต้องการควบคุมตำแหน่งความเร็ว แรงบิด ความแม่นยำ และความรวดเร็ว เพื่อให้เครื่องกลและไฟฟ้าคอนโทรลทำงานสอดคล้องกันอย่างมีประสิทธิภาพ โดยใช้การควบคุมแบบป้อนกลับ (Feedback Controller) ซึ่งคือระบบควบคุมที่มีการวัดค่าเอาต์พุตของระบบ แล้วนำมาเปรียบเทียบกับค่าอินพุตเพื่อควบคุมและปรับแต่งให้ค่าเอาต์พุตของระบบให้มีค่า เท่ากับหรือใกล้เคียงกับค่าอินพุต
<br><br><br>
<h3 align="center">Liquid Crystal Display</h3>
<p align="center"> 
<img src="https://dc.lnwfile.com/_/dc/_raw/4b/47/bm.jpg" height="300" width="400">
  </p>
เป็นจอที่แสดงผลเป็นตัวอักษรตามช่องแบบตายตัว เช่น จอ LCD ขนาด 16x2 หมายถึงใน 1 แถว มีตัวอักษรใส่ได้ 16 ตัว และมีทั้งหมด 2 บรรทัดให้ใช้งาน ส่วน 20x4 จะหมายถึงใน 1 แถว มีตัวอักษรใส่ได้ 20 ตัว และมีทั้งหมด 2 บรรทัด<br><br>


# Status
<b>Borad Microcontroller&nbsp;: Uncompleted</b><br>
<b>Poster&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: Uncompleted</b><br>
<b>Presentation Video &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;: Uncompleted</b><br>
<b>Lastest Update : 30 April 2019 00:47 AM</b><br>
<a href="https://www.youtube.com/"><b>Presentation Video</b></a>
# Author 
 <b>IT KMITL#16</b> <br />
 1.Mr.  Jakkrapat  Suwanno    61070022 <br />
 2.Mr.  Jirat thongpeng       61070027 <br />
 3.Mr.  Chanathip Chuchuay    61070033 <br />
 4.Mr.  Punyapat Plangpranet  61070122 <br />
 
<center><table>
 <tr>
  <th><img src="src/ong.jpg" height="150" width="150"></th>
  <th><img src="src/man.jpg" height="150" width="150"></th>
  <th><img src="src/yew.jpg" height="150" width="150"></th>
  <th><img src="src/kitt.jpg" height="150" width="150"></th>
 </tr>
 <tr>
  <th><p align="center">Jakkrapat  Suwanno</p></th> 
  <th><p align="center">Jirat thongpeng   </p></th>
  <th><p align="center">Chanathip Chuchuay</p></th>
  <th><p align="center">Punyapat Plangpranet</p></th>
 </tr>
 <tr>
  <th><p align="center">61070022</p></th>
  <th><p align="center">61070027</p></th>
  <th><p align="center">61070033</p></th>
  <th><p align="center">61070122</p></th>
 </table></center>
 
<br />

# References 
<a href=E#>#</a><br />
<a href=#>#</a>
<br />
<br />
[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)



