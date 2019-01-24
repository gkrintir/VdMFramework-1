void xsecsPerScan_PCC()
{
//=========Macro generated from canvas: can/
//=========  (Mon Nov 20 15:51:48 2017) by ROOT version5.99/05
   TCanvas *can = new TCanvas("can", "",1,1,800,576);
   can->SetHighLightColor(2);
   can->Range(-4.470349e-08,8.510945,6,8.619839);
   can->SetFillColor(0);
   can->SetBorderMode(0);
   can->SetBorderSize(2);
   can->SetFrameBorderMode(0);
   can->SetFrameBorderMode(0);
   
   Double_t _fx1007[5] = {
   3,
   5,
   4,
   2,
   1};
   Double_t _fy1007[5] = {
   8.541747,
   8.576138,
   8.554691,
   8.575614,
   8.58695};
   Double_t _fex1007[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t _fey1007[5] = {
   0.01265231,
   0.01243986,
   0.0115265,
   0.01537343,
   0.01474014};
   TGraphErrors *gre = new TGraphErrors(5,_fx1007,_fy1007,_fex1007,_fey1007);
   gre->SetName("");
   gre->SetTitle(";Scan Pair;#sigma_{Vis} (Barn)");
   gre->SetFillColor(1);

   Int_t ci;   // for color index setting
   ci = TColor::GetColor("#00cc00");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1007 = new TH1F("Graph_Graph1007","",100,0.6,5.4);
   Graph_Graph1007->SetMinimum(8.521835);
   Graph_Graph1007->SetMaximum(8.60895);
   Graph_Graph1007->SetDirectory(0);
   Graph_Graph1007->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1007->SetLineColor(ci);
   Graph_Graph1007->GetXaxis()->SetTitle("Scan Pair");
   Graph_Graph1007->GetXaxis()->SetLabelFont(42);
   Graph_Graph1007->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1007->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1007->GetXaxis()->SetTitleFont(42);
   Graph_Graph1007->GetYaxis()->SetTitle("#sigma_{Vis} (Barn)");
   Graph_Graph1007->GetYaxis()->SetLabelFont(42);
   Graph_Graph1007->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1007->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1007->GetYaxis()->SetTitleFont(42);
   Graph_Graph1007->GetZaxis()->SetLabelFont(42);
   Graph_Graph1007->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1007->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1007->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1007);
   
   gre->Draw("ap");
   TLatex *   tex = new TLatex(0.93,0.88,"2016  (13 TeV)");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.15,0.88,"CMS #bf{#scale[0.75]{#it{Preliminary}}}");
tex->SetNDC();
   tex->SetLineWidth(2);
   tex->Draw();
   can->Modified();
   can->cd();
   can->SetSelected(can);
}
