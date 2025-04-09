# 🖥️ Project - Computer Store with C++

> Project ร้านขายสินค้าคอมพิวเตอร์ ด้วยภาษา C++

## 🛠️ Features
- **ระบบสมาชิก**: ผู้ใช้สามารถสมัครสมาชิกเพื่อสร้างบัญชีและเข้าสู่ระบบในการใช้งานระบบ 
- **ตะกร้าสินค้า**: ระบบตะกร้าสินค้าให้ผู้ใช้สามารถเลือกสินค้าหลายๆ ชิ้นและทำการตรวจสอบและสั่งซื้อได้ 
- **เก็บข้อมูลในไฟล์ .txt**: ข้อมูลผู้ใช้และการทำรายการต่างๆ จะถูกเก็บลงในไฟล์ `.txt` เพื่อการจัดการข้อมูลที่สะดวก 
- **ระบบคัดกรองสินค้า**: ผู้ใช้สามารถคัดกรองสินค้าตามหมวดหมู่ ราคา หรือคุณสมบัติอื่นๆ เพื่อเลือกสินค้าที่ต้องการได้ง่ายขึ้น 

## 📜 License

This project is open-source under the MIT License. Let me know if you need any modifications! 🚀

## 🗺️ Project Structure

```bash
project-computer-store-cpp/
├── LICENSE         # File containing the license (MIT License)
├── README.md       # Documentation file explaining how to use the project
├── main.cpp        # Main C file
├── user/           # Users Folder
|     ├── cart.txt          # User Cart File
|     ├── member_id.txt     # User Id File
|     ├── password.txt      # User Password File
|     └── username.txt      # User Name File
├── stock/          # Stocks Folder
|     ├── stock_id.txt      # Stock Id Lists File
|     ├── stock_list.txt    # Stock Name Lists File
|     └── stock_value.txt   # Stock Value Lists File
├── junk/           # Temps Folder
|     ├── password.txt      # User Password Temp File
|     ├── username.txt      # User Name Temp File
|     └── cart/     # Carts Folder
|           └── cart.txt    # Cart Temp File
```

## ⚙️ Installation 
To run this Project:

```bash
git clone https://github.com/zChuckyX/project-computer-store-cpp.git
```
```bash
cd project-computer-store-cpp
```
```bash
gcc main.cpp -o main.exe
```
```bash
main.exe
```
