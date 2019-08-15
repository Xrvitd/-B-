x = raw_data.AZ;
y = raw_data.EL;
n = csvread("config.csv");
%n = table2array(n);
n = n';
[r,c] = size(n);
ans = zeros(73,37,2);
for k = 1:r
    z = zeros(73,37,2);
    for i =1 : 32
        if(i~=4 && i~=20 && n(k,i)>0 && n(k,i)<5)
            a = 10.^(raw_data.LogMag(:,:,i,n(k,i))./20).*cos(deg2rad(Phase(:,:,i,n(k,i))));
            b = 10.^(raw_data.LogMag(:,:,i,n(k,i))./20).*sin(deg2rad(Phase(:,:,i,n(k,i))));
            z = z + cat(3,a,b);
        end
    end
    ans = z;
    Z = 20.*log10(sqrt(ans(:,:,1).^2+ans(:,:,2).^2));

    Z(39,20)
    Z(39,21)

end
%(37:42,17:22)

%c= colorbar;
%c.Ticks = [0:0.1:1];
%c.TickLabels = floor(minint:(maxint-minint)/10:maxint)
%c.FontSize = 25;
%c.FontWeight = 'bold';
%c.Label.String = "MagLog/dBm";
