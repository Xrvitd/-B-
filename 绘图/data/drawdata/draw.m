x = raw_data.AZ;
y = raw_data.EL;
for i =1:15
subplot(3,5,i)
%figure(1)
%z = 10.^(raw_data.LogMag(:,:,i,1)./20);
%x = x + pi
%[xx,yy,zz] = sph2cart(x,y,z)
%contourf(x(25:49,10:28),y(31:43,16:22),z(25:49,10:28),[30.0,35.0])
z = csvread("C:\Users\Xrvitd_PC\Dropbox\ÉîÛÚ±­\data\byÊý¾Ý\data\drawdata\"+i+".csv");
z = z(:,1:37);
[C,h] = contourf(x(25:49,10:28)',y(25:49,10:28)',z(25:49,10:28)');
h.LevelList = 30:1:40;
%h.ShowText = "on";
colormap(jet);
caxis([30,37]);
xlabel("AZ/¡ã");
ylabel("EL/¡ã");
title("N_{bs}= "+i,"FontSize",25);
%print(gcf,'-dpng', '-r600', filename(i));
set(gca,'FontSize',25);
set(gca,'FontWeight','bold');
end
caxis([30,37]);
c = colorbar;
c.Ticks = [30:1:37];
c.TickLabels = [30:1:37];
c.Label.String = 'LogMag/dBm';
c.FontSize = 25;
set(gcf,'PaperPositionMode','auto');