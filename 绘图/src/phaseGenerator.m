Phase = zeros(32,4,73,37);
x = [1:4]';
vb = [];
for k = 1:1
    A = raw_data.Phase(:,:,k,:);
    A = squeeze(A);
    A = permute(A,[3,1,2]);
    [B,I] = sort(A);
    for i = 1:73
        for j = 1:37
            y = A(:,i,j);
            T  = fit(x,y,'90*x+b','start',90);
            a = 90*x+T.b;
            Phase(k,I(:,i,j),i,j) = a(x);
            vb(k,i,j) = T.b;
        end
    end
end
