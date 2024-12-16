import { Component, OnInit } from '@angular/core';
import { DataService } from '../data.service';
@Component({
  selector: 'app-detail',
  templateUrl: './detail.component.html',
  styleUrls: ['./detail.component.css']
})
export class DetailComponent implements OnInit {
  datas: any;
  constructor(private dataService: DataService) { }

  ngOnInit(): void {
    this.dataService.getData().subscribe(
      (data) => {
        console.log(data)
        this.datas = data.data;
      },
      (error) => {
        console.error('Error fetching data: ', error);
      }
    );
  }

}
