{
//=========Macro generated from canvas: c1/c1
//=========  (Sun Feb  7 16:36:16 2016) by ROOT version5.34/32
   TCanvas *c1 = new TCanvas("c1", "c1",1,1,700,476);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   c1->SetHighLightColor(2);
   c1->Range(-367.0375,0.1316048,3303.338,1.19131);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   TGraphErrors *gre = new TGraphErrors(5);
   gre->SetName("");
   gre->SetTitle("4266 PCC DGConst Const");
   gre->SetFillColor(1);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(20);
   gre->SetMarkerSize(0.4);
   gre->SetPoint(0,1631,0.58243);
   gre->SetPointError(0,0,0.02059511);
   gre->SetPoint(1,2211,0.513042);
   gre->SetPointError(1,0,0.04654016);
   gre->SetPoint(2,771,0.4009826);
   gre->SetPointError(2,0,0.03875023);
   gre->SetPoint(3,51,0.4339785);
   gre->SetPointError(3,0,0.0390993);
   gre->SetPoint(4,2674,0.585969);
   gre->SetPointError(4,0,0.04543472);
   
   TH1F *Graph_Graph63 = new TH1F("Graph_Graph63","4266 PCC DGConst Const",100,0,2936.3);
   Graph_Graph63->SetMinimum(0.2375753);
   Graph_Graph63->SetMaximum(1.085339);
   Graph_Graph63->SetDirectory(0);
   Graph_Graph63->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph63->SetLineColor(ci);
   Graph_Graph63->GetXaxis()->SetTitle("BCID");
   Graph_Graph63->GetXaxis()->SetLabelFont(42);
   Graph_Graph63->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph63->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph63->GetXaxis()->SetTitleFont(42);
   Graph_Graph63->GetYaxis()->SetTitle("Const");
   Graph_Graph63->GetYaxis()->SetLabelFont(42);
   Graph_Graph63->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph63->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph63->GetYaxis()->SetTitleFont(42);
   Graph_Graph63->GetZaxis()->SetLabelFont(42);
   Graph_Graph63->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph63->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph63->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph63);
   
   gre->Draw("ap");
   
   gre = new TGraphErrors(5);
   gre->SetName("");
   gre->SetTitle("4266 PCC DGConst Const  Scan 2");
   gre->SetFillColor(1);
   gre->SetMarkerColor(3);
   gre->SetMarkerStyle(21);
   gre->SetMarkerSize(0.4);
   gre->SetPoint(0,1631,0.6328864);
   gre->SetPointError(0,0,4.183943e-05);
   gre->SetPoint(1,2211,0.5715487);
   gre->SetPointError(1,0,8.695503e-05);
   gre->SetPoint(2,771,0.4944512);
   gre->SetPointError(2,0,5.060525e-06);
   gre->SetPoint(3,51,0.5840848);
   gre->SetPointError(3,0,0.02073696);
   gre->SetPoint(4,2674,0.5673999);
   gre->SetPointError(4,0,0.03164515);
   
   TH1F *Graph_Graph64 = new TH1F("Graph_Graph64","4266 PCC DGConst Const  Scan 2",100,0,2936.3);
   Graph_Graph64->SetMinimum(0.4805979);
   Graph_Graph64->SetMaximum(0.6467765);
   Graph_Graph64->SetDirectory(0);
   Graph_Graph64->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph64->SetLineColor(ci);
   Graph_Graph64->GetXaxis()->SetLabelFont(42);
   Graph_Graph64->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph64->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph64->GetXaxis()->SetTitleFont(42);
   Graph_Graph64->GetYaxis()->SetLabelFont(42);
   Graph_Graph64->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph64->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph64->GetYaxis()->SetTitleFont(42);
   Graph_Graph64->GetZaxis()->SetLabelFont(42);
   Graph_Graph64->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph64->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph64->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph64);
   
   gre->Draw("p");
   
   gre = new TGraphErrors(5);
   gre->SetName("");
   gre->SetTitle("4266 PCC DGConst Const  Scan 3");
   gre->SetFillColor(1);
   gre->SetMarkerColor(4);
   gre->SetMarkerStyle(22);
   gre->SetMarkerSize(0.4);
   gre->SetPoint(0,1631,0.667527);
   gre->SetPointError(0,0,0.02033184);
   gre->SetPoint(1,2211,0.6519402);
   gre->SetPointError(1,0,9.296847e-05);
   gre->SetPoint(2,771,0.6020281);
   gre->SetPointError(2,0,0.01846347);
   gre->SetPoint(3,51,0.6497364);
   gre->SetPointError(3,0,0.02090305);
   gre->SetPoint(4,2674,0.7343847);
   gre->SetPointError(4,0,0.02124114);
   
   TH1F *Graph_Graph65 = new TH1F("Graph_Graph65","4266 PCC DGConst Const  Scan 3",100,0,2936.3);
   Graph_Graph65->SetMinimum(0.5663585);
   Graph_Graph65->SetMaximum(0.7728319);
   Graph_Graph65->SetDirectory(0);
   Graph_Graph65->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph65->SetLineColor(ci);
   Graph_Graph65->GetXaxis()->SetLabelFont(42);
   Graph_Graph65->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph65->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph65->GetXaxis()->SetTitleFont(42);
   Graph_Graph65->GetYaxis()->SetLabelFont(42);
   Graph_Graph65->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph65->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph65->GetYaxis()->SetTitleFont(42);
   Graph_Graph65->GetZaxis()->SetLabelFont(42);
   Graph_Graph65->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph65->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph65->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph65);
   
   gre->Draw("p");
   
   gre = new TGraphErrors(5);
   gre->SetName("");
   gre->SetTitle("4266 PCC DGConst Const  Scan 4");
   gre->SetFillColor(1);
   gre->SetMarkerColor(6);
   gre->SetMarkerStyle(23);
   gre->SetMarkerSize(0.4);
   gre->SetPoint(0,1631,0.5580458);
   gre->SetPointError(0,0,0.04379625);
   gre->SetPoint(1,2211,0.5404177);
   gre->SetPointError(1,0,0.04273513);
   gre->SetPoint(2,771,0.3);
   gre->SetPointError(2,0,0.02112482);
   gre->SetPoint(3,51,0.6813541);
   gre->SetPointError(3,0,0.0005501709);
   gre->SetPoint(4,2674,0.5676948);
   gre->SetPointError(4,0,0.0422418);
   
   TH1F *Graph_Graph66 = new TH1F("Graph_Graph66","4266 PCC DGConst Const  Scan 4",100,0,2936.3);
   Graph_Graph66->SetMinimum(0.2385723);
   Graph_Graph66->SetMaximum(0.7222071);
   Graph_Graph66->SetDirectory(0);
   Graph_Graph66->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph66->SetLineColor(ci);
   Graph_Graph66->GetXaxis()->SetLabelFont(42);
   Graph_Graph66->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph66->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph66->GetXaxis()->SetTitleFont(42);
   Graph_Graph66->GetYaxis()->SetLabelFont(42);
   Graph_Graph66->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph66->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph66->GetYaxis()->SetTitleFont(42);
   Graph_Graph66->GetZaxis()->SetLabelFont(42);
   Graph_Graph66->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph66->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph66->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph66);
   
   gre->Draw("p");
   
   gre = new TGraphErrors(5);
   gre->SetName("");
   gre->SetTitle("4266 PCC DGConst Const  Scan 5");
   gre->SetFillColor(1);
   gre->SetMarkerColor(7);
   gre->SetMarkerStyle(24);
   gre->SetMarkerSize(0.4);
   gre->SetPoint(0,1631,0.8290988);
   gre->SetPointError(0,0,0.0002616662);
   gre->SetPoint(1,2211,0.503626);
   gre->SetPointError(1,0,0.1470493);
   gre->SetPoint(2,771,0.6532528);
   gre->SetPointError(2,0,0.1482469);
   gre->SetPoint(3,51,0.4146923);
   gre->SetPointError(3,0,0.1375895);
   gre->SetPoint(4,2674,0.9242473);
   gre->SetPointError(4,0,0.04368826);
   
   TH1F *Graph_Graph67 = new TH1F("Graph_Graph67","4266 PCC DGConst Const  Scan 5",100,0,2936.3);
   Graph_Graph67->SetMinimum(0.2080195);
   Graph_Graph67->SetMaximum(1.037019);
   Graph_Graph67->SetDirectory(0);
   Graph_Graph67->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph67->SetLineColor(ci);
   Graph_Graph67->GetXaxis()->SetLabelFont(42);
   Graph_Graph67->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph67->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph67->GetXaxis()->SetTitleFont(42);
   Graph_Graph67->GetYaxis()->SetLabelFont(42);
   Graph_Graph67->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph67->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph67->GetYaxis()->SetTitleFont(42);
   Graph_Graph67->GetZaxis()->SetLabelFont(42);
   Graph_Graph67->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph67->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph67->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph67);
   
   gre->Draw("p");
   
   gre = new TGraphErrors(5);
   gre->SetName("");
   gre->SetTitle("4266 PCC DGConst Const  Scan 6");
   gre->SetFillColor(1);
   gre->SetMarkerColor(2);
   gre->SetMarkerStyle(25);
   gre->SetMarkerSize(0.4);
   gre->SetPoint(0,1631,0.5849489);
   gre->SetPointError(0,0,0.03207467);
   gre->SetPoint(1,2211,0.4101483);
   gre->SetPointError(1,0,0.08327384);
   gre->SetPoint(2,771,0.5594852);
   gre->SetPointError(2,0,0.0006251189);
   gre->SetPoint(3,51,0.5583039);
   gre->SetPointError(3,0,0.03451025);
   gre->SetPoint(4,2674,0.5938516);
   gre->SetPointError(4,0,0.03143384);
   
   TH1F *Graph_Graph68 = new TH1F("Graph_Graph68","4266 PCC DGConst Const  Scan 6",100,0,2936.3);
   Graph_Graph68->SetMinimum(0.2970334);
   Graph_Graph68->SetMaximum(0.6551265);
   Graph_Graph68->SetDirectory(0);
   Graph_Graph68->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph68->SetLineColor(ci);
   Graph_Graph68->GetXaxis()->SetLabelFont(42);
   Graph_Graph68->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph68->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph68->GetXaxis()->SetTitleFont(42);
   Graph_Graph68->GetYaxis()->SetLabelFont(42);
   Graph_Graph68->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph68->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph68->GetYaxis()->SetTitleFont(42);
   Graph_Graph68->GetZaxis()->SetLabelFont(42);
   Graph_Graph68->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph68->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph68->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph68);
   
   gre->Draw("p");
   
   gre = new TGraphErrors(5);
   gre->SetName("");
   gre->SetTitle("4266 PCC DGConst Const  Scan 7");
   gre->SetFillColor(1);
   gre->SetMarkerColor(3);
   gre->SetMarkerStyle(26);
   gre->SetMarkerSize(0.4);
   gre->SetPoint(0,1631,0.3);
   gre->SetPointError(0,0,0.1626664);
   gre->SetPoint(1,2211,0.365607);
   gre->SetPointError(1,0,0.1381636);
   gre->SetPoint(2,771,0.4982778);
   gre->SetPointError(2,0,0.1453875);
   gre->SetPoint(3,51,0.5295665);
   gre->SetPointError(3,0,0.1610912);
   gre->SetPoint(4,2674,0.8301426);
   gre->SetPointError(4,0,0.03719838);
   
   TH1F *Graph_Graph69 = new TH1F("Graph_Graph69","4266 PCC DGConst Const  Scan 7",100,0,2936.3);
   Graph_Graph69->SetMinimum(0.06433292);
   Graph_Graph69->SetMaximum(0.9403417);
   Graph_Graph69->SetDirectory(0);
   Graph_Graph69->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph69->SetLineColor(ci);
   Graph_Graph69->GetXaxis()->SetLabelFont(42);
   Graph_Graph69->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph69->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph69->GetXaxis()->SetTitleFont(42);
   Graph_Graph69->GetYaxis()->SetLabelFont(42);
   Graph_Graph69->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph69->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph69->GetYaxis()->SetTitleFont(42);
   Graph_Graph69->GetZaxis()->SetLabelFont(42);
   Graph_Graph69->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph69->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph69->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph69);
   
   gre->Draw("p");
   
   gre = new TGraphErrors(5);
   gre->SetName("");
   gre->SetTitle("4266 PCC DGConst Const  Scan 8");
   gre->SetFillColor(1);
   gre->SetMarkerColor(4);
   gre->SetMarkerStyle(27);
   gre->SetMarkerSize(0.4);
   gre->SetPoint(0,1631,0.6861204);
   gre->SetPointError(0,0,0.001284145);
   gre->SetPoint(1,2211,0.6446175);
   gre->SetPointError(1,0,3.085505e-06);
   gre->SetPoint(2,771,0.6645676);
   gre->SetPointError(2,0,0.001469275);
   gre->SetPoint(3,51,0.6979579);
   gre->SetPointError(3,0,0.0006762917);
   gre->SetPoint(4,2674,0.8454039);
   gre->SetPointError(4,0,0.002484733);
   
   TH1F *Graph_Graph70 = new TH1F("Graph_Graph70","4266 PCC DGConst Const  Scan 8",100,0,2936.3);
   Graph_Graph70->SetMinimum(0.6242869);
   Graph_Graph70->SetMaximum(0.868216);
   Graph_Graph70->SetDirectory(0);
   Graph_Graph70->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph70->SetLineColor(ci);
   Graph_Graph70->GetXaxis()->SetLabelFont(42);
   Graph_Graph70->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph70->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph70->GetXaxis()->SetTitleFont(42);
   Graph_Graph70->GetYaxis()->SetLabelFont(42);
   Graph_Graph70->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph70->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph70->GetYaxis()->SetTitleFont(42);
   Graph_Graph70->GetZaxis()->SetLabelFont(42);
   Graph_Graph70->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph70->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph70->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph70);
   
   gre->Draw("p");
   
   gre = new TGraphErrors(5);
   gre->SetName("");
   gre->SetTitle("4266 PCC DGConst Const  Scan 9");
   gre->SetFillColor(1);
   gre->SetMarkerColor(6);
   gre->SetMarkerStyle(28);
   gre->SetMarkerSize(0.4);
   gre->SetPoint(0,1631,0.4662557);
   gre->SetPointError(0,0,0.04493947);
   gre->SetPoint(1,2211,0.4067124);
   gre->SetPointError(1,0,0.06146208);
   gre->SetPoint(2,771,0.3);
   gre->SetPointError(2,0,0.1305362);
   gre->SetPoint(3,51,0.4398995);
   gre->SetPointError(3,0,0.1055243);
   gre->SetPoint(4,2674,0.4385215);
   gre->SetPointError(4,0,0.07252194);
   
   TH1F *Graph_Graph71 = new TH1F("Graph_Graph71","4266 PCC DGConst Const  Scan 9",100,0,2936.3);
   Graph_Graph71->SetMinimum(0.1318678);
   Graph_Graph71->SetMaximum(0.5830198);
   Graph_Graph71->SetDirectory(0);
   Graph_Graph71->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph71->SetLineColor(ci);
   Graph_Graph71->GetXaxis()->SetLabelFont(42);
   Graph_Graph71->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph71->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph71->GetXaxis()->SetTitleFont(42);
   Graph_Graph71->GetYaxis()->SetLabelFont(42);
   Graph_Graph71->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph71->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph71->GetYaxis()->SetTitleFont(42);
   Graph_Graph71->GetZaxis()->SetLabelFont(42);
   Graph_Graph71->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph71->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph71->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph71);
   
   gre->Draw("p");
   
   gre = new TGraphErrors(5);
   gre->SetName("");
   gre->SetTitle("4266 PCC DGConst Const  Scan 10");
   gre->SetFillColor(1);
   gre->SetMarkerColor(7);
   gre->SetMarkerStyle(29);
   gre->SetMarkerSize(0.4);
   gre->SetPoint(0,1631,0.5759284);
   gre->SetPointError(0,0,0.02926255);
   gre->SetPoint(1,2211,0.6039441);
   gre->SetPointError(1,0,0.02062651);
   gre->SetPoint(2,771,0.5219308);
   gre->SetPointError(2,0,0.01639761);
   gre->SetPoint(3,51,0.6168572);
   gre->SetPointError(3,0,0.02163703);
   gre->SetPoint(4,2674,0.5834403);
   gre->SetPointError(4,0,6.603844e-05);
   
   TH1F *Graph_Graph72 = new TH1F("Graph_Graph72","4266 PCC DGConst Const  Scan 10",100,0,2936.3);
   Graph_Graph72->SetMinimum(0.4922371);
   Graph_Graph72->SetMaximum(0.6517903);
   Graph_Graph72->SetDirectory(0);
   Graph_Graph72->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph72->SetLineColor(ci);
   Graph_Graph72->GetXaxis()->SetLabelFont(42);
   Graph_Graph72->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph72->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph72->GetXaxis()->SetTitleFont(42);
   Graph_Graph72->GetYaxis()->SetLabelFont(42);
   Graph_Graph72->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph72->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph72->GetYaxis()->SetTitleFont(42);
   Graph_Graph72->GetZaxis()->SetLabelFont(42);
   Graph_Graph72->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph72->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph72->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph72);
   
   gre->Draw("p");
   
   TLegend *leg = new TLegend(0.65,0.8,0.95,0.95,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("","4266 PCC DGConst Const Scan  1","lpf");
   entry->SetFillColor(1);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.4);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","4266 PCC DGConst Const  Scan 2","lpf");
   entry->SetFillColor(1);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(3);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(0.4);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","4266 PCC DGConst Const  Scan 3","lpf");
   entry->SetFillColor(1);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(4);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(0.4);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","4266 PCC DGConst Const  Scan 4","lpf");
   entry->SetFillColor(1);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(6);
   entry->SetMarkerStyle(23);
   entry->SetMarkerSize(0.4);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","4266 PCC DGConst Const  Scan 5","lpf");
   entry->SetFillColor(1);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(7);
   entry->SetMarkerStyle(24);
   entry->SetMarkerSize(0.4);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","4266 PCC DGConst Const  Scan 6","lpf");
   entry->SetFillColor(1);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(25);
   entry->SetMarkerSize(0.4);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","4266 PCC DGConst Const  Scan 7","lpf");
   entry->SetFillColor(1);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(3);
   entry->SetMarkerStyle(26);
   entry->SetMarkerSize(0.4);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","4266 PCC DGConst Const  Scan 8","lpf");
   entry->SetFillColor(1);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(4);
   entry->SetMarkerStyle(27);
   entry->SetMarkerSize(0.4);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","4266 PCC DGConst Const  Scan 9","lpf");
   entry->SetFillColor(1);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(6);
   entry->SetMarkerStyle(28);
   entry->SetMarkerSize(0.4);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","4266 PCC DGConst Const  Scan 10","lpf");
   entry->SetFillColor(1);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(7);
   entry->SetMarkerStyle(29);
   entry->SetMarkerSize(0.4);
   entry->SetTextFont(42);
   leg->Draw();
   
   TPaveText *pt = new TPaveText(0.2773563,0.94,0.7226437,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *text = pt->AddText("4266 PCC DGConst Const");
   pt->Draw();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
