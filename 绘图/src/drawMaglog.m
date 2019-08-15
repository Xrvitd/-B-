x = raw_data.AZ;
y = raw_data.EL;
%names = csvread("C:/Users/Xrvitd/Dropbox/深圳杯/data/by数据/data/sj_3/csvname.csv");
figure(1);
%z = csvread("C:/Users/Xrvitd/Dropbox/深圳杯/data/by数据/data/sj_3/"+i+".csv");
z = table2array(test(:,1:37));
[C,h] = contourf(x(25:49,10:28)',y(25:49,10:28)',z(25:49,10:28)');
h.LevelList = 30:1:40;
h.LevelStep =5;
colorbar;
set(gca,'FontSize',15);
set(gca,'FontWeight','bold');
colormap(jet);
figure(2);
[C,h] = contourf(x(31:43,16:22)',y(31:43,16:22)',z(31:43,16:22)');
h.LevelList = 30:0.5:40;
h.LevelStep = 0.5;
%caxis([30,40])
colorbar;
