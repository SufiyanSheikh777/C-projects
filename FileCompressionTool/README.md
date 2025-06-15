Here's a complete and clean `README.md` content for your **File Compression Tool** GitHub repository:

---

## 📦 File Compression Tool in C

A simple CLI-based file compression and decompression tool written in C using **Run-Length Encoding (RLE)**. This project demonstrates basic data compression, optional encryption, and file handling using modular programming in C.

---

### 📁 Project Structure

```
FileCompressionTool/
├── main.c         // Entry point and menu system
├── codec.c        // Compression and decompression logic
├── codec.h        // Header file with function declarations
├── Makefile       // For easy compilation
├── input.txt      // Sample input file for testing
```

---

### 🔧 Features

* 🗜️ Compress text files using Run-Length Encoding (RLE)
* 🔓 Decompress files back to original content
* 🔐 Optional XOR encryption using a user-provided password *(optional, can be removed)*
* 📉 Displays compression ratio and file sizes
* 🧩 Modular code for easy maintenance

---

### 🚀 How to Compile & Run

#### ✅ Using Make:

```bash
make
./compressor
```

#### 🔄 Without Make:

```bash
gcc -c main.c
gcc -c codec.c
gcc -o compressor main.o codec.o
./compressor
```

---

### 📌 Sample Output

```
--- File Compression Tool ---
1. Compress File
2. Decompress File
3. Exit
Enter your choice: 1
Enter input file to compress: input.txt
Enter output compressed file: compressed.txt
Set a password: 1234
Compression successful!
Original Size: 486 bytes
Compressed Size: 288 bytes
Compression Ratio: 40.74%
```

---

### 🧪 Example Input

Contents of `input.txt`:

```
Compression is the process of reducing the size of data to save space or transmission time...
```

After compression, the tool generates `compressed.txt` with encoded (and optionally encrypted) content.

Use option 2 from the menu to decompress and restore the original file into `output.txt`.

---

### 📌 Concepts Used

* Run-Length Encoding (RLE)
* File I/O in C
* XOR encryption (optional)
* Modular programming
* Use of Makefile

---

### 📁 License

This project is open-source and free to use under the MIT License.

---
