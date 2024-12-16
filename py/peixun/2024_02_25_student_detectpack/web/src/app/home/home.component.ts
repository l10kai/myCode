import { Component, OnInit } from '@angular/core';
import { DataService } from '../data.service'; // 假设你的服务名为 DataService
import { Router } from '@angular/router';


@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.css']
})
export class HomeComponent  {
  attendanceCount: number = 0;
  // @ts-ignore
  selectedFiles: any;

  constructor(private dataService: DataService, private router: Router) {}

  onFileSelected(event: any) {
    this.selectedFiles = event.target.files;
  }

  uploadData() {
    if (this.selectedFiles && this.selectedFiles.length > 0) {
      this.router.navigate(['/detail']);
      this.dataService.uploadFilesAndData(this.selectedFiles, this.attendanceCount).subscribe(
        response => {
          console.log('Upload successful', response);
          // 使用Router进行路由导航
        },
        error => {
          console.error('Upload error', error);
          alert('上传失败，请重试！'); // 显示警告消息
          this.attendanceCount = 0; // 清空变量
          this.selectedFiles = null; // 清空选择的文件
        }
      );
    }
  }

}
