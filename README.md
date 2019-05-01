<h1 align="center"> 
Ultrascanic
</h1>

# Description 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Mini Project นี้เป็นการนำเสนอ Microcontroller Project โดยตัวหลักที่จะใช้คือ <a href=https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf>HC-SR04</a> ซึ่งเป็นตัวส่งสัญญาณ Ultrasonic (คลื่นความถี่วิทยุ) โดยป้อนไฟให้ขา VCC และ GND โมดูลนี้ มีขาสัญญาณดิจิทัล TRIG (อินพุต) และ ECHO (เอาต์พุต) ที่นำไปเชื่อมต่อกับไมโครคอนโทรลเลอร์ได้ อย่างเช่น Arduino ในการวัดระยะห่างแต่ละครั้ง จะต้องสร้างสัญญาณแบบ Pulse ที่มีความกว้าง (Pulse Width) อย่างน้อย 10 usec ป้อนให้ขา TRIG และหลังจากนั้นให้วัดความกว้างของสัญญาณช่วง HIGH จากขา ECHO ถ้าวัตถุอยู่ใกล้ <b>ความกว้างของสัญญาณ Pulse ที่ได้ก็จะน้อย แต่ถ้าวัตถุอยู่ไกลออกไป ก็จะได้ค่าความกว้างของสัญญาณ Pulse ที่มากขึ้น</b> <br><br>
<b>- ใช้แรงดันประมาณ +5V </b><br>
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
<a href=http://database.esportsobserver.com/>TEO Professional</a><br />
<a href=https://www.esportsearnings.com/>e-Sports Earnings</a>
<br />
<br />
[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)



