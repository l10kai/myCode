import { Injectable } from '@angular/core';
import { HttpClient, HttpEvent, HttpRequest } from '@angular/common/http';
import { Observable } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class DataService {

  constructor(private http: HttpClient) {}

  uploadFilesAndData(files: FileList, attendance: number): Observable<HttpEvent<any>> {
    const formData: FormData = new FormData();
    Array.from(files).forEach(file => formData.append('files', file));
    formData.append('attendance', attendance.toString());

    const req = new HttpRequest('POST', 'http://localhost:5000/upload', formData, {
      reportProgress: true,
      responseType: 'json'
    });

    return this.http.request(req);
  }

  getData(): Observable<any> {
    return this.http.get('http://localhost:5000/getdata');
  }
}
